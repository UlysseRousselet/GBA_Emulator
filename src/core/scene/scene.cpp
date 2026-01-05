/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "C_Core.hpp"
#include "GbaUtils.hpp"

void SceneManager::loadAllComponents()
{
    registry->register_component<CPU>();
    registry->register_component<Memory>();
}

void SceneManager::loadAllSystems()
{
    registry->add_system<CPU, Memory>(execute_system);
}

void SceneManager::loadAllRooms()
{
    for (int i = 0; i < this->roomFounds.size(); i++) {
        if (roomFounds[i].substr(roomFounds[i].find_last_of(".") + 1) == "gb") {
             std::ifstream file(roomFounds[i], std::ios::binary | std::ios::ate);
            if (!file) continue;
            std::streamsize size = file.tellg();
            if (size <= 0) continue;
            file.seekg(0, std::ios::beg);
            std::vector<uint8_t> rom(size);
            file.read(reinterpret_cast<char*>(rom.data()), size);
            Entity newEntity = registry->spawn_entity();
            registry->add_component<Memory>(newEntity, Memory{rom});
            registry->add_component<CPU>(newEntity, CPU{0x01, 0xB0, 0x00, 0x13, 0x00, 0xD8, 0x01, 0x4D, 0xFFFE, 0x0100, {
                {0x00, [](CPU &cpu, Memory &mem) { /* NOP */ }},
                {0xC3, jp_C3},
                {0x01, ld_01}, {0x02, ld_02}, {0x11, ld_11}, {0x12, ld_12}, {0x21, ld_21}, {0x22, ld_22}, {0x31, ld_31}, {0x32, ld_32}, {0x40, ld_40}, {0x41, ld_41}, {0x42, ld_42}, {0x0E, ld_0E}, {0x06, ld_06}, 
                {0x43, ld_43}, {0x44, ld_44}, {0x45, ld_45}, {0x46, ld_46}, {0x47, ld_47}, {0x48, ld_48}, {0x49, ld_49}, {0x4A, ld_4A}, {0x4B, ld_4B}, {0x4C, ld_4C}, {0x4D, ld_4D}, {0x4E, ld_4E}, {0x4F, ld_4F},
                {0x50, ld_50}, {0x51, ld_51}, {0x52, ld_52}, {0x53, ld_53}, {0x54, ld_54}, {0x55, ld_55}, {0x56, ld_56}, {0x57, ld_57}, {0x58, ld_58}, {0x59, ld_59}, {0x5A, ld_5A}, {0x5B, ld_5B}, {0x5C, ld_5C}, {0x5D, ld_5D}, {0x5E, ld_5E}, {0x5F, ld_5F},
                {0x60, ld_60}, {0x61, ld_61}, {0x62, ld_62}, {0x63, ld_63}, {0x64, ld_64}, {0x65, ld_65}, {0x66, ld_66}, {0x67, ld_67}, {0x68, ld_68}, {0x69, ld_69}, {0x6A, ld_6A}, {0x6B, ld_6B}, {0x6C, ld_6C}, {0x6D, ld_6D}, {0x6E, ld_6E}, {0x6F, ld_6F},
                {0x70, ld_70}, {0x71, ld_71}, {0x72, ld_72}, {0x73, ld_73}, {0x74, ld_74}, {0x75, ld_75}, {0x77, ld_77}, {0x78, ld_78}, {0x79, ld_79}, {0x7A, ld_7A}, {0x7B, ld_7B}, {0x7C, ld_7C}, {0x7D, ld_7D}, {0x7E, ld_7E}, {0x7F, ld_7F},
                {0xAF, xor_AF},
            }});
        }
    }
}   