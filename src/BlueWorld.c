#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "BlueWorld.h"

uint8_t Parity(uint8_t num) {
    return 0;
}

void addInstr(State8080 *state, uint8_t registerVal, uint8_t carry) {
    uint16_t answer = (uint16_t) state->a + (uint16_t) registerVal;
    state->cc.z = ((answer & 0xff) == 0);
    state->cc.s = ((answer & 0x80) != 0);
    state->cc.cy = (answer > 0xff);
    state->cc.p = Parity(answer & 0xff);
    state->a = answer & 0xff;
}

void Emulate8080(State8080* state) {
    unsigned char *opcode = &state->memory[state->pc];

    switch(*opcode) {
        case 0x00: break; //NOP is easy!
        case 0x01:  //LXI   B,word
            state->c = opcode[1];
            state->b = opcode[2];
            state->pc += 2; //Advance 2 more bytes
            break;
        case 0x02: break;
        case 0x03: break;
        case 0x04: break;
        case 0x05: break;
        case 0x06: break;
        case 0x07: break;
        case 0x08: break;
        case 0x09: break;
        case 0x0a: break;
        case 0x0b: break;
        case 0x0c: break;
        case 0x0d: break;
        case 0x0e: break;
        case 0x0f: break;
        case 0x10: break;
        case 0x11: break;
        case 0x12: break;
        case 0x13: break;
        case 0x14: break;
        case 0x15: break;
        case 0x16: break;
        case 0x17: break;
        case 0x18: break;
        case 0x19: break;
        case 0x1a: break;
        case 0x1b: break;
        case 0x1c: break;
        case 0x1d: break;
        case 0x1e: break;
        case 0x1f: break;
        case 0x20: break;
        case 0x21: break;
        case 0x22: break;
        case 0x23: break;
        case 0x24: break;
        case 0x25: break;
        case 0x26: break;
        case 0x27: break;
        case 0x28: break;
        case 0x29: break;
        case 0x2a: break;
        case 0x2b: break;
        case 0x2c: break;
        case 0x2d: break;
        case 0x2e: break;
        case 0x2f: break;
        case 0x30: break;
        case 0x31: break;
        case 0x32: break;
        case 0x33: break;
        case 0x34: break;
        case 0x35: break;
        case 0x36: break;
        case 0x37: break;
        case 0x38: break;
        case 0x39: break;
        case 0x3a: break;
        case 0x3b: break;
        case 0x3c: break;
        case 0x3d: break;
        case 0x3e: break;
        case 0x3f: break;
        case 0x40: state->b = state->b; break; //MOV B,B
        case 0x41: state->b = state->c; break; //MOV B,C
        case 0x42: state->b = state->d; break; //MOV B,D
        case 0x43: state->b = state->e; break; //MOV B,E
        case 0x44: state->b = state->h; break; //MOV B,H
        case 0x45: state->b = state->l; break; //MOV B,L
        case 0x46: state->b = (state->h<<8) | (state->l); break; //MOV B,M
        case 0x47: state->b = state->a; break; //MOV B, A
        case 0x48: state->c = state->b; break;
        case 0x49: state->c = state->c; break;
        case 0x4a: state->c = state->d; break;
        case 0x4b: state->c = state->e; break;
        case 0x4c: state->c = state->h; break;
        case 0x4d: state->c = state->l; break;
        case 0x4e: state->c = (state->h<<8) | (state->l); break;
        case 0x4f: state->c = state->a; break;
        case 0x50: state->d = state->b; break;
        case 0x51: state->d = state->c; break;
        case 0x52: state->d = state->d; break;
        case 0x53: state->d = state->e; break;
        case 0x54: state->d = state->h; break;
        case 0x55: state->d = state->l; break;
        case 0x56: state->d = (state->h<<8) | (state->l); break;
        case 0x57: state->d = state->a; break;
        case 0x58: state->e = state->b; break;
        case 0x59: state->e = state->c; break;
        case 0x5a: state->e = state->d; break;
        case 0x5b: state->e = state->e; break;
        case 0x5c: state->e = state->h; break;
        case 0x5d: state->e = state->l; break;
        case 0x5e: state->e = (state->h<<8) | (state->l); break;
        case 0x5f: state->e = state->a; break;
        case 0x60: state->h = state->a; break;
        case 0x61: state->h = state->a; break;
        case 0x62: state->h = state->a; break;
        case 0x63: state->h = state->a; break;
        case 0x64: state->h = state->a; break;
        case 0x65: state->h = state->a; break;
        case 0x66: state->h = (state->h<<8) | (state->l); break;
        case 0x67: state->h = state->a; break;
        case 0x68: state->l = state->b; break;
        case 0x69: state->l = state->d; break;
        case 0x6a: state->l = state->e; break;
        case 0x6b: state->l = state->h; break;
        case 0x6c: state->l = state->l; break;
        case 0x6d: state->l = state->l; break;
        case 0x6e: state->l = (state->h<<8) | (state->l); break;
        case 0x6f: state->l = state->a; break;
        case 0x70: break;
        case 0x71: break;
        case 0x72: break;
        case 0x73: break;
        case 0x74: break;
        case 0x75: break; //MOV M, L
        case 0x76: break;
        case 0x77: break; // HLT
        case 0x78: state->a = state->b; break;
        case 0x79: state->a = state->c; break;
        case 0x7a: state->a = state->d; break;
        case 0x7b: state->a = state->e; break;
        case 0x7c: state->a = state->h; break;
        case 0x7d: state->a = state->l; break;
        case 0x7e: state->a = (state->h<<8) | (state->l); break;
        case 0x7f: state->a = state->a; break;
        case 0x80: addInstr(state, state->b, 0); break; // ADD B
        case 0x81: addInstr(state, state->c, 0); break; // ADD C
        case 0x82: addInstr(state, state->d, 0); break; // ADD D
        case 0x83: addInstr(state, state->e, 0); break; // ADD E
        case 0x84: addInstr(state, state->h, 0); break; // ADD H
        case 0x85: addInstr(state, state->l, 0); break; // ADD L
        case 0x86: {
            uint16_t offset = (state->h << 8) | (state->l);
            uint16_t answer = (uint16_t) state->a + state->memory[offset];
            state->cc.z = ((answer & 0xff) == 0);
            state->cc.s = ((answer & 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
        }
        case 0x87: addInstr(state, state->a, 0); break;
        case 0x88: break;
        case 0x89: break;
        case 0x8a: break;
        case 0x8b: break;
        case 0x8c: break;
        case 0x8d: break;
        case 0x8e: break;
        case 0x8f: break;
        case 0x90: break;
        case 0x91: break;
        case 0x92: break;
        case 0x93: break;
        case 0x94: break;
        case 0x95: break;
        case 0x96: break;
        case 0x97: break;
        case 0x98: break;
        case 0x99: break;
        case 0x9a: break;
        case 0x9b: break;
        case 0x9c: break;
        case 0x9d: break;
        case 0x9e: break;
        case 0x9f: break;
        case 0xa0: break;
        case 0xa1: break;
        case 0xa2: break;
        case 0xa3: break;
        case 0xa4: break;
        case 0xa5: break;
        case 0xa6: break;
        case 0xa7: break;
        case 0xa8: break;
        case 0xa9: break;
        case 0xaa: break;
        case 0xab: break;
        case 0xac: break;
        case 0xad: break;
        case 0xae: break;
        case 0xaf: break;
        case 0xb0: break;
        case 0xb1: break;
        case 0xb2: break;
        case 0xb3: break;
        case 0xb4: break;
        case 0xb5: break;
        case 0xb6: break;
        case 0xb7: break;
        case 0xb8: break;
        case 0xb9: break;
        case 0xba: break;
        case 0xbb: break;
        case 0xbc: break;
        case 0xbd: break;
        case 0xbe: break;
        case 0xbf: break;
        case 0xc0: break;
        case 0xc1: break;
        case 0xc2: break;
        case 0xc3: break;
        case 0xc4: break;
        case 0xc5: break;
        case 0xc6: {
            uint16_t answer = (uint16_t) state->a+ (uint16_t) opcode[1];
            state->cc.z = ((answer & 0xff) == 0);
            state->cc.s = ((answer & 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
        } break;
        case 0xc7: break;
        case 0xc8: break;
        case 0xc9: break;
        case 0xca: break;
        case 0xcb: break;
        case 0xcc: break;
        case 0xcd: break;
        case 0xce: break;
        case 0xcf: break;
        case 0xd0: break;
        case 0xd1: break;
        case 0xd2: break;
        case 0xd3: break;
        case 0xd4: break;
        case 0xd5: break;
        case 0xd6: break;
        case 0xd7: break;
        case 0xd8: break;
        case 0xd9: break;
        case 0xda: break;
        case 0xdb: break;
        case 0xdc: break;
        case 0xdd: break;
        case 0xde: break;
        case 0xdf: break;
        case 0xe0: break;
        case 0xe1: break;
        case 0xe2: break;
        case 0xe3: break;
        case 0xe4: break;
        case 0xe5: break;
        case 0xe6: break;
        case 0xe7: break;
        case 0xe8: break;
        case 0xe9: break;
        case 0xea: break;
        case 0xeb: break;
        case 0xec: break;
        case 0xed: break;
        case 0xee: break;
        case 0xef: break;
        case 0xf0: break;
        case 0xf1: break;
        case 0xf2: break;
        case 0xf3: break;
        case 0xf4: break;
        case 0xf5: break;
        case 0xf6: break;
        case 0xf7: break;
        case 0xf8: break;
        case 0xf9: break;
        case 0xfa: break;
        case 0xfb: break;
        case 0xfc: break;
        case 0xfd: break;
        case 0xfe: break;
        case 0xff: break;
    }
    state->pc+=1;
}


int main(int argc, char **argv) {
    if (argc != 2 || strcmp(argv[1], "-h") == 0) {
        printf("\tUsage: ");
        return 1;
    }
    printf("---------- BlueWorld Intel 8080 Emulator ----------");
    State8080 *state8080 = malloc(sizeof(State8080));
    Emulate8080(state8080);

    free(state8080);
    return 0;
}
