/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** position_system.hpp
*/

#include "C_Systems.hpp"

void position_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<Velocity> &velocity)
{
    (void)registry;
    float deltaTime = 0.0f;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            deltaTime = windows[i].value().deltaTime;
        }
    }

    for (size_t i = 0; i < velocity.size(); i++) {

        if (position[i].has_value() && velocity[i].has_value()) {
            if (position[i].value().x < -100 || position[i].value().x > 1380 || position[i].value().y < -100 || position[i].value().y > 820) {
                registry.kill_entity(registry.entity_from_index(i));
                continue;
            }

            position[i].value().x += velocity[i].value().x * deltaTime;
            position[i].value().y += velocity[i].value().y * deltaTime;
        }
    }
}
