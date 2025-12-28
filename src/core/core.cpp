/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "C_Core.hpp"

Core::Core(std::shared_ptr<Registry> registry, int ac, char **av) : registry(registry), sceneManager(registry, ac, av)
{
    this->sceneManager.loadAllComponents();
    this->sceneManager.loadAllSystems();
    this->sceneManager.loadAllRooms();

    this->loop();
}

Core::~Core()
{}

void Core::loop()
{
    while (1) {
        registry->run_systems();
    }
}