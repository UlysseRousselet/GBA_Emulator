/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** execute_system.hpp
*/

#include "C_Systems.hpp"
#include "GbaUtils.hpp"

void execute_loop(Registry &registry, CPU &cpu, Memory &mem)
{
    uint8_t opcode = fetch(cpu, mem);
    printf("PC = %d, valeur: %d, valeur EXA: %02X\n", cpu.PC - 1, opcode, opcode);

    if (!(cpu.instructions.find(opcode) == cpu.instructions.end())) {
        cpu.instructions.at(opcode)(cpu, mem);
    } else {
        printf("Opcode %02X not implemented\n", opcode);
        exit(EXIT_FAILURE);
    }
}
