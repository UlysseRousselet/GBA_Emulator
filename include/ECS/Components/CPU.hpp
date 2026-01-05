#ifndef CPU_HPP
#define CPU_HPP

#include "Memory.hpp"
#include <cstdint>
#include <map>
#include <functional>

struct CPU {
    uint8_t A, F, B, C, D, E, H, L;
    uint16_t SP, PC;
    std::map<uint8_t, std::function<void(CPU&, Memory&)>> instructions;
};

#endif
