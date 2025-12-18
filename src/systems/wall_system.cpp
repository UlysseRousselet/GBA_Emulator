/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** position_system.hpp
*/

#include "C_Systems.hpp"

void wall_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<Wall> &wall,
                 Sparse_array<Drawable> &drawable, Sparse_array<Player> &player)
{
    (void)registry;
    float deltaTime = 0.0f;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            deltaTime = windows[i].value().deltaTime;
        }
    }

    for (size_t i = 0; i < wall.size() && drawable.size(); i++) {
        if (wall[i].has_value() && drawable[i].has_value() && position.size()) {
            for (size_t j = 0; j < player.size() && j < position.size() && j < drawable.size(); j++) {
                if (player[j].has_value() && position[j].has_value() && drawable[j].has_value()) {
                    sf::IntRect &wallRect = drawable[i].value().frameRect;
                    sf::IntRect &playerRect = drawable[j].value().frameRect;

                    if (position[j].value().x + playerRect.width > position[i].value().x &&
                        position[j].value().x < position[i].value().x + wallRect.width &&
                        position[j].value().y + playerRect.height > position[i].value().y &&
                        position[j].value().y < position[i].value().y + wallRect.height) {
                        if (position[i].value().y > position[j].value().y) {
                            position[j].value().y = position[i].value().y - playerRect.height;
                        } else if (position[i].value().y < position[j].value().y) {
                            position[j].value().y = position[i].value().y + wallRect.height;
                        }
                    }
                }
            }
        }
    }
}
