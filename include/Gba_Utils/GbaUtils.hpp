#ifndef GBAUTILS_HPP
#define GBAUTILS_HPP
#include "Registry.hpp"
#include "CPU.hpp"
#include "Memory.hpp"

void execute_loop(Registry &registry, CPU &cpu, Memory &mem);
uint8_t fetch(CPU &cpu, Memory &mem);

void jp_C3(CPU &cpu, Memory &mem);

void jr_20(CPU &cpu, Memory &mem);

// LD instructions
void ld_01(CPU &cpu, Memory &mem);
void ld_02(CPU &cpu, Memory &mem);
void ld_06(CPU &cpu, Memory &mem);
void ld_0E(CPU &cpu, Memory &mem);
void ld_11(CPU &cpu, Memory &mem);
void ld_12(CPU &cpu, Memory &mem);
void ld_21(CPU &cpu, Memory &mem);
void ld_22(CPU &cpu, Memory &mem);
void ld_31(CPU &cpu, Memory &mem);
void ld_32(CPU &cpu, Memory &mem);
void ld_3E(CPU &cpu, Memory &mem);
void ld_40(CPU &cpu, Memory &mem);
void ld_41(CPU &cpu, Memory &mem);
void ld_42(CPU &cpu, Memory &mem);
void ld_43(CPU &cpu, Memory &mem);
void ld_44(CPU &cpu, Memory &mem);
void ld_45(CPU &cpu, Memory &mem);
void ld_46(CPU &cpu, Memory &mem);
void ld_47(CPU &cpu, Memory &mem);
void ld_48(CPU &cpu, Memory &mem);
void ld_49(CPU &cpu, Memory &mem);
void ld_4A(CPU &cpu, Memory &mem);
void ld_4B(CPU &cpu, Memory &mem);
void ld_4C(CPU &cpu, Memory &mem);
void ld_4D(CPU &cpu, Memory &mem);
void ld_4E(CPU &cpu, Memory &mem);
void ld_4F(CPU &cpu, Memory &mem);
void ld_50(CPU &cpu, Memory &mem);
void ld_51(CPU &cpu, Memory &mem);
void ld_52(CPU &cpu, Memory &mem);
void ld_53(CPU &cpu, Memory &mem);
void ld_54(CPU &cpu, Memory &mem);
void ld_55(CPU &cpu, Memory &mem);
void ld_56(CPU &cpu, Memory &mem);
void ld_57(CPU &cpu, Memory &mem);
void ld_58(CPU &cpu, Memory &mem);
void ld_59(CPU &cpu, Memory &mem);
void ld_5A(CPU &cpu, Memory &mem);
void ld_5B(CPU &cpu, Memory &mem);
void ld_5C(CPU &cpu, Memory &mem);
void ld_5D(CPU &cpu, Memory &mem);
void ld_5E(CPU &cpu, Memory &mem);
void ld_5F(CPU &cpu, Memory &mem);
void ld_60(CPU &cpu, Memory &mem);
void ld_61(CPU &cpu, Memory &mem);
void ld_62(CPU &cpu, Memory &mem);
void ld_63(CPU &cpu, Memory &mem);
void ld_64(CPU &cpu, Memory &mem);
void ld_65(CPU &cpu, Memory &mem);
void ld_66(CPU &cpu, Memory &mem);
void ld_67(CPU &cpu, Memory &mem);
void ld_68(CPU &cpu, Memory &mem);
void ld_69(CPU &cpu, Memory &mem);
void ld_6A(CPU &cpu, Memory &mem);
void ld_6B(CPU &cpu, Memory &mem);
void ld_6C(CPU &cpu, Memory &mem);
void ld_6D(CPU &cpu, Memory &mem);
void ld_6E(CPU &cpu, Memory &mem);
void ld_6F(CPU &cpu, Memory &mem);
void ld_70(CPU &cpu, Memory &mem);
void ld_71(CPU &cpu, Memory &mem);
void ld_72(CPU &cpu, Memory &mem);
void ld_73(CPU &cpu, Memory &mem);
void ld_74(CPU &cpu, Memory &mem);
void ld_75(CPU &cpu, Memory &mem);
void ld_77(CPU &cpu, Memory &mem);
void ld_78(CPU &cpu, Memory &mem);
void ld_79(CPU &cpu, Memory &mem);
void ld_7A(CPU &cpu, Memory &mem);
void ld_7B(CPU &cpu, Memory &mem);
void ld_7C(CPU &cpu, Memory &mem);
void ld_7D(CPU &cpu, Memory &mem);
void ld_7E(CPU &cpu, Memory &mem);
void ld_7F(CPU &cpu, Memory &mem);
void ld_E0(CPU &cpu, Memory &mem);
void ld_F0(CPU &cpu, Memory &mem);

void xor_AF(CPU &cpu, Memory &mem);

void dec_05(CPU &cpu, Memory &mem);
void dec_0D(CPU &cpu, Memory &mem);

void di_F3(CPU &cpu, Memory &mem);

#endif /* GBAUTILS_HPP */