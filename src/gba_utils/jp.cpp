#include "GbaUtils.hpp"

void jp_C3(CPU &cpu, Memory &mem)
{
    uint8_t low = fetch(cpu, mem);
    uint8_t high = fetch(cpu, mem);
    cpu.PC = (high << 8) | low;
}