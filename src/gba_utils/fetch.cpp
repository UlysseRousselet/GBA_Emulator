#include "GbaUtils.hpp"

uint8_t fetch(CPU &cpu, Memory &mem)
{
    return mem.data[cpu.PC++];
}