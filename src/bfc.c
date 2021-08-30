#include <stdio.h>
#include <string.h>

#include "linux.c"

typedef unsigned char byte;

int main(int argc, char* argv[])
{
	char *in = 0, *out = 0;
	for(int i=1; i<argc; i++) {
		//printf("Argument %d:%s\n",i,argv[i]);
		if(!strcmp(argv[i], "--in"))
		{
			if(i==argc-1)
			{
				printf("Missing input file.\n");
				return -1;
			}
			if(argv[i+1][0]=='-')
			{
				printf("Incorrect operand order.\n");
				return -1;
			}
			in = argv[++i];
			continue;
		}
		if(!strcmp(argv[i], "--out"))
		{
			if(i==argc-1)
			{
				printf("Missing output file.\n");
				return -1;
			}
			if(argv[i+1][0]=='-')
			{
				printf("Incorrect operand order.\n");
				return -1;
			}
			out = argv[++i];
			continue;
		}
	}
	if(!in) { printf("Missing input file.\n"); return -1;}
	if(!out) { printf("Missing output file.\n"); return -1;}
	FILE *fin = 0, *fout = 0; 
	fin = fopen(in, "r");
	if(!fin) { printf("Input file couldn't be read.\n"); return -1;}
	fout = fopen(out, "wb+");
	if(!fout) { printf("Output file couldn't be created.\n"); return -1;}
	for (int i=0, c=0; c!=EOF; c=freadc(fin)) {
		switch(c) {
			case '>':
				byte data[]={0x47, 0x8B, 0x17};
				fwrite((void*)data, sizeof(byte), sizeof(data), fout);
				break;
			case '<':
				byte data[]={0x4F, 0x8B, 0x17};
				fwrite((void*)data, sizeof(byte), sizeof(data), fout);
				break;
			case '+':
				byte data[]={0x42, 0x89, 0x17};
				fwrite((void*)data, sizeof(byte), sizeof(data), fout);
				break;
			case '-':
				byte data[]={0x4A, 0x89, 0x17};
				fwrite((void*)data, sizeof(byte), sizeof(data), fout);
				break;
			case '.':
				byte data[] = {0xB8, 0x04, 0x00, 0x00, 0x00, 0xBB, 0x01, 0x00, 0x00, 0x00, 0xCD, 0x80};
				fwrite((void*)data, sizeof(byte), sizeof(data), fout);
				break;
			case ',':
				byte data[] = {0xB8, 0x04, 0x00, 0x00, 0x00, 0xBB, 0x01, 0x00, 0x00, 0x00, 0xCD, 0x80};
				fwrite((void*)data, sizeof(byte), sizeof(data), fout);
				break;
			}
		i++;
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
