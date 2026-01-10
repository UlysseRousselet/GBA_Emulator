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

// Add the missing ld function here
void ld_2A(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.A = mem.data[address];
}

void ld_3E(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    cpu.A = op;
}

void ld_20(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.B = mem.data[address];
}

void ld_24(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.C = mem.data[address];
}

void ld_28(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.D = mem.data[address];
}

void ld_2C(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.E = mem.data[address];
}
