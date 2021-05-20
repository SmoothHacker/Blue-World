#include <stdio.h>
#include <string.h>

#include "disassembler.h"

int main(int argc, char **argv) {
    if (argc != 2 || strcmp(argv[1], "-h") == 0) {
        printf("\tUsage: ./disassembler binary\n");
        return 1;
    }

    fileProcessor(argv[1]);

    printf("Disassembly for %s:\n\n", argv[1]);
    while (pc < fileSize) {
        printf("%04x ", pc);
        pc += disassembleToConsole();
    }

    return 0;
}
