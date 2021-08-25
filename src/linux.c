unsigned char linx86[] = {
// Taken from David Smith's "1 Handmade Linux x86 executable: ELF header"
// Little endian 32-bit header
				// All numbers (except in names) are in base sixteen (hexadecimal)
				// 00 <- number of bytes listed so far
0x7F,	0x45,	0x4C,	0x46,	// 04 e_ident[EI_MAG]: ELF magic number
0x01,				// 05 e_ident[EI_CLASS]: 1: 32-bit, 2: 64-bit
	0x01,			// 06 e_ident[EI_DATA]: 1: little-endian, 2: big-endian
		0x01,		// 07 e_ident[EI_VERSION]: ELF header version; must be 1
			0x00,	// 08 e_ident[EI_OSABI]: Target OS ABI; should be 0

0x00,				// 09 e_ident[EI_ABIVERSION]: ABI version; 0 is ok for Linux
	0x00,	0x00,	0x00,	// 0C e_ident[EI_PAD]: unused, should be 0
0x00,	0x00,	0x00,	0x00,	// 10

0x02,	0x00,			// 12 e_type: object file type; 2: executable
	0x03,	0x00,		// 14 e_machine: instruction set architecture; 3: x86, 3E: amd64
0x01,	0x00,	0x00,	0x00,	// 18 e_version: ELF identification version; must be 1

0x54,	0x80,	0x04,	0x08,	// 1C e_entry: memory address of entry point (where process starts)
0x34,	0x00,	0x00,	0x00,	// 20 e_phoff: file offset where program headers begin

0x00,	0x00,	0x00,	0x00,	// 24 e_shoff: file offset where section headers begin
0x00,	0x00,	0x00,	0x00,	// 28 e_flags: 0 for x86

0x34,	0x00,			// 2A e_ehsize: size of this header (34: 32-bit, 40: 64-bit)
	0x20,	0x00,		// 2C e_phentsize: size of each program header (20: 32-bit, 38: 64-bit)
0x01,	0x00,			// 2E e_phnum: #program headers
	0x28,	0x00,		// 30 e_shentsize: size of each section header (28: 32-bit, 40: 64-bit)

0x00,	0x00,			// 32 e_shnum: #section headers
	0x00,	0x00,		// 34 e_shstrndx: index of section header containing section names

// >>>>>>>>>>>>> ELF PROGRAM HEADER <<<<<<<<<<<<< 

0x01,	0x00,	0x00,	0x00,	// 38 p_type: segment type; 1: loadable

0x54,	0x00,	0x00,	0x00,	// 3C p_offset: file offset where segment begins
0x54,	0x80,	0x04,	0x08,	// 40 p_vaddr: virtual address of segment in memory (x86: 08048054)
    
0x00,	0x00,	0x00,	0x00,	// 44 p_paddr: physical address of segment, unspecified by 386 supplement
0x0C,	0x00,	0x00,	0x00,	// 48 p_filesz: size in bytes of the segment in the file image ############

0x0C,	0x00,	0x00,	0x00,	// 4C p_memsz: size in bytes of the segment in memory; p_filesz <= p_memsz
0x05,	0x00,	0x00,	0x00,	// 50 p_flags: segment-dependent flags (1: X, 2: W, 4: R)

0x00,	0x10,	0x00,	0x00,	// 54 p_align: 1000 for x86
};
unsigned char linx86e[] = {
// >>>>>>>>>>>>> PROGRAM SEGMENT <<<<<<<<<<<<< 
0xB8,	0x01,	0x00,	0x00,	0x00,	// 59 eax <- 1 (exit)
0xBB,	0x05,	0x00,	0x00,	0x00,	// 5E ebx <- 0 (param)
0xCD,	0x80				// 60 syscall >> int 80
//int 80 syscall, write 4, stdout fd is 1
//int imm8	/ CD ib
//mov r32, imm32/ B8+rd id, eax is B8 
};

