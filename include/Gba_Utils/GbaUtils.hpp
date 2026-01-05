#ifndef GBAUTILS_HPP
#define GBAUTILS_HPP
#include "Registry.hpp"
#include "CPU.hpp"
#include "Memory.hpp"

void execute_loop(Registry &registry, CPU &cpu, Memory &mem);
uint8_t fetch(CPU &cpu, Memory &mem);

void jp_C3(CPU &cpu, Memory &mem);
void ld_21(CPU &cpu, Memory &mem);
void ld_0E(CPU &cpu, Memory &mem);
void ld_06(CPU &cpu, Memory &mem);
void xor_AF(CPU &cpu, Memory &mem);

#endif /* GBAUTILS_HPP */