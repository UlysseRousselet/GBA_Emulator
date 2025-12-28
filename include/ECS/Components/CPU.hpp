#include <cstdint>
#ifndef CPU_HPP
#define CPU_HPP

struct CPU {
    uint8_t A, F, B, C, D, E, H, L;
    uint16_t SP, PC;
};

#endif
