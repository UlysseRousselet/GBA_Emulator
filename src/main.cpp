/*
** EPITECH, 2024
** Projet perso
** File description:
** main
*/

#include <iostream>
#include "C_Core.hpp"
#include "Registry.hpp"

int main(int argc, char **argv)
{
    std::shared_ptr<Registry> registry_ptr = std::make_shared<Registry>();

    try {
        Core core(registry_ptr, argc, argv);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
