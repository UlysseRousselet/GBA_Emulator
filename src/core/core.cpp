/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "C_Core.hpp"

Core::Core(std::shared_ptr<Registry> registry) : registry(registry), sceneManager(registry)
{
    this->sceneManager.loadAllComponents();
    this->sceneManager.loadAllSystems();

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