/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** execute_system.hpp
*/

#include "C_Systems.hpp"

uint8_t fetch(Registry &registry, CPU &cpu, Memory &mem)
{
    return mem.data[cpu.PC++];
}

void execute_loop(Registry &registry, CPU &cpu, Memory &mem)
{
    uint8_t opcode = fetch(registry, cpu, mem);
    printf("PC = %d, valeur: %d, valeur EXA: %02X\n", cpu.PC - 1, opcode, opcode);
    switch (opcode) {
        case 0x00:
            break;
        case 0xC3:
            {
                uint8_t low = fetch(registry, cpu, mem);
                uint8_t high = fetch(registry, cpu, mem);
                cpu.PC = (high << 8) | low;
            }
        break;
    }
}

void execute_system(Registry &registry, Sparse_array<CPU> &cpu, Sparse_array<Memory> &mem)
{
    for (size_t i = 0; i < cpu.size() && i < mem.size(); i++) {
        if (cpu[i].has_value() && mem[i].has_value()) {
            execute_loop(registry, cpu[i].value(), mem[i].value());
        }
    }
}
