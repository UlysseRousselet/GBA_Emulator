/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** images_system
*/

#include "C_Systems.hpp"
#include <cmath>

void force_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Player> &players, Sparse_array<Force> &forces,
                  Sparse_array<Position> &position)
{

    for (size_t i = 0; i < players.size(); i++) {
        if (players[i].has_value()) {
            for (size_t j = 0; j < forces.size(); j++) {
                if (forces[j].has_value() && position[i].has_value() && position[j].has_value() &&
                    players[i].value().id == forces[j].value().playerId && forces[j].value().snapped) {
                    position[j].value().x = position[i].value().x + 100;
                    position[j].value().y = position[i].value().y - 14;
                }
            }
        }
    }
}
