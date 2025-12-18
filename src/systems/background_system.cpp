/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** draw_system.hpp
*/

#include "C_Systems.hpp"

void background_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Background> &background)
{
    std::shared_ptr<sf::RenderWindow> window;
    float deltaTime = 0.0f;

    bool isGame = false;
    bool isLobby = false;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i].value().window;
            deltaTime = windows[i].value().deltaTime;
            isGame = windows[i].value().isGame;
            isLobby = windows[i].value().isLobby;
            break;
        }
    }

    if (!isGame && !isLobby) {
        return;
    }

    for (size_t i = 0; i < background.size(); i++) {
        auto &bg = background[i];

        if (bg.has_value()) {
            auto &sprite = bg.value().sprite;
            auto &sprite2 = bg.value().sprite2;

            // bouger les sprites vers la gauche
            float speed = -50.0f;
            sf::Vector2f movement(speed * deltaTime, 0.0f);

            sprite.move(movement);  // Move the first sprite
            sprite2.move(movement); // Move the second sprite

            if (sprite.getPosition().x <= -1280) {
                // bouge la preums sprite a droite quand offscreen
                sprite.setPosition(sprite2.getPosition().x + 1280, 0);
            }

            if (sprite2.getPosition().x <= -1280) {
                // bouge la deuxieme sprite quand offscreen
                sprite2.setPosition(sprite.getPosition().x + 1280, 0);
            }

            window->draw(sprite);
            window->draw(sprite2);
        }
    }
}
