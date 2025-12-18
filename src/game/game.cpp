/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "C_Game.hpp"

Game::Game(std::shared_ptr<Registry> registry) : registry(registry), sceneManager(registry)
{
    this->sceneManager.loadAllComponents();
    this->sceneManager.loadAllSystems();

    this->loop();
}

Game::~Game()
{}

void Game::loop()
{
    while (1) {
        registry->run_systems();
    }
}