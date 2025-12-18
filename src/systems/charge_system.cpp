/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** charge_system.hpp
*/

#include "C_Systems.hpp"

void charge_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Charging> &charge, Sparse_array<Position> &position,
                   Sparse_array<Player> &player)
{
    for (size_t i = 0; i < charge.size(); i++) {
        if (charge[i].has_value()) {
            for (size_t j = 0; j < player.size(); j++) {
                if (player[j].has_value() && charge[i]->id == player[j]->id && position[j].has_value()) {
                    position[i].value().x = position[j].value().x + 90;
                    position[i].value().y = position[j].value().y + 5;
                }
            }
        }
    }
}
