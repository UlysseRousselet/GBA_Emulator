#include "GbaUtils.hpp"

void jr_20(CPU &cpu, Memory &mem)
{
    int8_t offset = static_cast<int8_t>(fetch(cpu, mem));
    if ((cpu.F & 0x80) == 0) { // Z == 0
        cpu.PC += offset;
    }
}