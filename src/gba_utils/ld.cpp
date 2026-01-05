#include "GbaUtils.hpp"

void ld_21(CPU &cpu, Memory &mem)
{
    uint8_t low = fetch(cpu, mem);
    uint8_t high = fetch(cpu, mem);
    cpu.L = low;
    cpu.H = high;
}

void ld_0E(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    cpu.C = op;
}

void ld_06(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    cpu.B = op;
}