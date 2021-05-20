#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <stdio.h>

extern unsigned char *programBuffer;
extern int pc;
extern long int fileSize; // Number of Bytes

void fileProcessor(char *fileInput);
int disassembleToConsole();

#endif
