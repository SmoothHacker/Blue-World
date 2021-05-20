cmake_minimum_required(VERSION 3.16)
project(Blue_World)

set(CMAKE_C_STANDARD 11)

add_executable(Blue_World src/BlueWorld.c src/BlueWorld.h)
add_executable(disassembler src/disassembler.c src/disassembler.h src/main_disassembler.c)