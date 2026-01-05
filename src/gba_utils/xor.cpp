#include "GbaUtils.hpp"

void xor_AF(CPU &cpu, Memory &mem)
{
    cpu.A = 0x00;
    cpu.F = 0x80;
}