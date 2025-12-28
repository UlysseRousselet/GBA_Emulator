/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** execute_system.hpp
*/

#include "C_Systems.hpp"

void execute_system(Registry &registry, Sparse_array<CPU> &cpu, Sparse_array<Memory> &mem)
{
    for (size_t i = 0; i < cpu.size() && i < mem.size(); i++) {
        if (cpu[i].has_value() && mem[i].has_value()) {
            std::cout << "test" << "\n";
        }
    }
}
