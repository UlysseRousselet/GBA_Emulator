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

// LD A, (HL+) (charge (HL) dans A puis incrémente HL)
void ld_2A(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.A = mem.data[address];
    cpu.L++;
    if (cpu.L == 0)
        cpu.H++;
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

void ld_3A(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.A = mem.data[address];
    if (cpu.L == 0) {
        cpu.H--;
        cpu.L = 0xFF;
    } else {
        cpu.L--;
    }
}

// LD L, n (charge immédiat dans L)
void ld_2E(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    cpu.L = op;
}

// LD (HL-), A (charge A dans (HL) puis décrémente HL)
void ld_32(CPU &cpu, Memory &mem)
{
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.A;
    if (cpu.L == 0) {
        cpu.H--;
        cpu.L = 0xFF;
    } else {
        cpu.L--;
    }
}

// LD (HL), n (charge immédiat dans (HL))
void ld_36(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = op;
}

// LD BC, nn (charge immédiat 16 bits dans BC)
void ld_01(CPU &cpu, Memory &mem)
{
    uint8_t low = fetch(cpu, mem);
    uint8_t high = fetch(cpu, mem);
    cpu.C = low;
    cpu.B = high;
}

// LD DE, nn (charge immédiat 16 bits dans DE)
void ld_11(CPU &cpu, Memory &mem)
{
    uint8_t low = fetch(cpu, mem);
    uint8_t high = fetch(cpu, mem);
    cpu.E = low;
    cpu.D = high;
}

// LD SP, nn (charge immédiat 16 bits dans SP)
void ld_31(CPU &cpu, Memory &mem)
{
    uint8_t low = fetch(cpu, mem);
    uint8_t high = fetch(cpu, mem);
    cpu.SP = (high << 8) | low;
}

// LD r1, r2 instructions (0x40-0x7F)
// 0x40-0x47: LD B, r
void ld_40(CPU &cpu, Memory &mem) { cpu.B = cpu.B; } // LD B, B (NOP)
void ld_41(CPU &cpu, Memory &mem) { cpu.B = cpu.C; }
void ld_42(CPU &cpu, Memory &mem) { cpu.B = cpu.D; }
void ld_43(CPU &cpu, Memory &mem) { cpu.B = cpu.E; }
void ld_44(CPU &cpu, Memory &mem) { cpu.B = cpu.H; }
void ld_45(CPU &cpu, Memory &mem) { cpu.B = cpu.L; }
void ld_46(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.B = mem.data[address];
}
void ld_47(CPU &cpu, Memory &mem) { cpu.B = cpu.A; }

// 0x48-0x4F: LD C, r
void ld_48(CPU &cpu, Memory &mem) { cpu.C = cpu.B; }
void ld_49(CPU &cpu, Memory &mem) { cpu.C = cpu.C; } // LD C, C (NOP)
void ld_4A(CPU &cpu, Memory &mem) { cpu.C = cpu.D; }
void ld_4B(CPU &cpu, Memory &mem) { cpu.C = cpu.E; }
void ld_4C(CPU &cpu, Memory &mem) { cpu.C = cpu.H; }
void ld_4D(CPU &cpu, Memory &mem) { cpu.C = cpu.L; }
void ld_4E(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.C = mem.data[address];
}
void ld_4F(CPU &cpu, Memory &mem) { cpu.C = cpu.A; }

// 0x50-0x57: LD D, r
void ld_50(CPU &cpu, Memory &mem) { cpu.D = cpu.B; }
void ld_51(CPU &cpu, Memory &mem) { cpu.D = cpu.C; }
void ld_52(CPU &cpu, Memory &mem) { cpu.D = cpu.D; } // LD D, D (NOP)
void ld_53(CPU &cpu, Memory &mem) { cpu.D = cpu.E; }
void ld_54(CPU &cpu, Memory &mem) { cpu.D = cpu.H; }
void ld_55(CPU &cpu, Memory &mem) { cpu.D = cpu.L; }
void ld_56(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.D = mem.data[address];
}
void ld_57(CPU &cpu, Memory &mem) { cpu.D = cpu.A; }

// 0x58-0x5F: LD E, r
void ld_58(CPU &cpu, Memory &mem) { cpu.E = cpu.B; }
void ld_59(CPU &cpu, Memory &mem) { cpu.E = cpu.C; }
void ld_5A(CPU &cpu, Memory &mem) { cpu.E = cpu.D; }
void ld_5B(CPU &cpu, Memory &mem) { cpu.E = cpu.E; } // LD E, E (NOP)
void ld_5C(CPU &cpu, Memory &mem) { cpu.E = cpu.H; }
void ld_5D(CPU &cpu, Memory &mem) { cpu.E = cpu.L; }
void ld_5E(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.E = mem.data[address];
}
void ld_5F(CPU &cpu, Memory &mem) { cpu.E = cpu.A; }

// 0x60-0x67: LD H, r
void ld_60(CPU &cpu, Memory &mem) { cpu.H = cpu.B; }
void ld_61(CPU &cpu, Memory &mem) { cpu.H = cpu.C; }
void ld_62(CPU &cpu, Memory &mem) { cpu.H = cpu.D; }
void ld_63(CPU &cpu, Memory &mem) { cpu.H = cpu.E; }
void ld_64(CPU &cpu, Memory &mem) { cpu.H = cpu.H; } // LD H, H (NOP)
void ld_65(CPU &cpu, Memory &mem) { cpu.H = cpu.L; }
void ld_66(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.H = mem.data[address];
}
void ld_67(CPU &cpu, Memory &mem) { cpu.H = cpu.A; }

// 0x68-0x6F: LD L, r
void ld_68(CPU &cpu, Memory &mem) { cpu.L = cpu.B; }
void ld_69(CPU &cpu, Memory &mem) { cpu.L = cpu.C; }
void ld_6A(CPU &cpu, Memory &mem) { cpu.L = cpu.D; }
void ld_6B(CPU &cpu, Memory &mem) { cpu.L = cpu.E; }
void ld_6C(CPU &cpu, Memory &mem) { cpu.L = cpu.H; }
void ld_6D(CPU &cpu, Memory &mem) { cpu.L = cpu.L; } // LD L, L (NOP)
void ld_6E(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.L = mem.data[address];
}
void ld_6F(CPU &cpu, Memory &mem) { cpu.L = cpu.A; }

// 0x70-0x77: LD (HL), r
void ld_70(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.B;
}
void ld_71(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.C;
}
void ld_72(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.D;
}
void ld_73(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.E;
}
void ld_74(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.H;
}
void ld_75(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.L;
}
// 0x76 is HALT, not LD
void ld_77(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    mem.data[address] = cpu.A;
}

// 0x78-0x7F: LD A, r
void ld_78(CPU &cpu, Memory &mem) { cpu.A = cpu.B; }
void ld_79(CPU &cpu, Memory &mem) { cpu.A = cpu.C; }
void ld_7A(CPU &cpu, Memory &mem) { cpu.A = cpu.D; }
void ld_7B(CPU &cpu, Memory &mem) { cpu.A = cpu.E; }
void ld_7C(CPU &cpu, Memory &mem) { cpu.A = cpu.H; }
void ld_7D(CPU &cpu, Memory &mem) { cpu.A = cpu.L; }
void ld_7E(CPU &cpu, Memory &mem) { 
    uint16_t address = (cpu.H << 8) | cpu.L;
    cpu.A = mem.data[address];
}
void ld_7F(CPU &cpu, Memory &mem) { cpu.A = cpu.A; } // LD A, A (NOP)

void ld_E0(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    mem.data[0xFF00 + op] = cpu.A;
}

void ld_F0(CPU &cpu, Memory &mem)
{
    uint8_t op = fetch(cpu, mem);
    cpu.A = mem.data[0xFF00 + op];
}