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
                {0x21, ld_21},
                {0xAF, xor_AF},
                {0x0E, ld_0E},
                {0x06, ld_06}
            }});
        }
    }
}