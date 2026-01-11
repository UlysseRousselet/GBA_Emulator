#include "GbaUtils.hpp"

void dec_05(CPU &cpu, Memory &mem)
{
    uint8_t oldB = cpu.B;
    cpu.B--;
    if (cpu.B == 0)
        cpu.F |= 0x80;
    else
        cpu.F &= ~0x80;
    cpu.F |= 0x40;
    // H
    if ((oldB & 0x0F) == 0)
        cpu.F |= 0x20;
    else
        cpu.F &= ~0x20;
}

void dec_0D(CPU &cpu, Memory &mem)
{
    uint8_t oldC = cpu.C;
    cpu.C--;
    if (cpu.C == 0)
        cpu.F |= 0x80;
    else
        cpu.F &= ~0x80;
    cpu.F |= 0x40;
    // H
    if ((oldC & 0x0F) == 0)
        cpu.F |= 0x20;
    else
        cpu.F &= ~0x20;
}