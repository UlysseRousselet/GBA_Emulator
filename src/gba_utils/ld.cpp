#include "GbaUtils.hpp"

void ld_02(CPU &cpu, Memory &mem)
{
    mem.data[(cpu.B << 8) | cpu.C] = cpu.A;
}

void ld_12(CPU &cpu, Memory &mem)
{
    mem.data[(cpu.D << 8) | cpu.E] = cpu.A;
}

void ld_21(CPU &cpu, Memory &mem)
{
    uint8_t low = fetch(cpu, mem);
    uint8_t high = fetch(cpu, mem);
    cpu.L = low;
    cpu.H = high;
}

void ld_22(CPU &cpu, Memory &mem)
{
    mem.data[(cpu.H << 8) | cpu.L] = cpu.A;
    cpu.L++;
    if (cpu.L == 0)
        cpu.H++;
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