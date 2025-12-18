/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/


#include "C_Game.hpp"
#include "Registry.hpp"

int main(int argc, char **argv)
{
    std::shared_ptr<Registry> registry_ptr = std::make_shared<Registry>();

    try {
        Game game(registry_ptr);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}