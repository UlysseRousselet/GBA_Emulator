/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** control_system.hpp
*/

#include "C_Systems.hpp"

void destroy_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Destroyable> &destroyable)
{
    std::shared_ptr<sf::RenderWindow> window;
    float deltaTime = 0.0f;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i].value().window;
            deltaTime = windows[i].value().deltaTime;
            break;
        }
    }

    for (size_t i = 0; i < destroyable.size(); i++) {
        auto &destroyComp = destroyable[i];

        if (destroyComp.has_value() && !destroyComp.value().isDestroyed) {
            auto &sprite = destroyComp.value().sprite;
            auto &frameRect = destroyComp.value().frameRect;
            auto frameCount = destroyComp.value().frameCount;
            auto &elapsedTime = destroyComp.value().elapsedTime;
            auto &currentFrame = destroyComp.value().currentFrame;
            auto &frameDuration = destroyComp.value().frameDuration;

            elapsedTime += deltaTime;

            if (elapsedTime >= frameDuration) {
                currentFrame++;
                if (currentFrame >= frameCount) {
                    registry.kill_entity(registry.entity_from_index(i));
                    continue;
                }

                sf::IntRect currentRect(frameRect.left + frameRect.width * currentFrame, frameRect.top, frameRect.width, frameRect.height);
                sprite.setTextureRect(currentRect);
                elapsedTime = 0.0f;
            }

            window->draw(sprite);
        }
    }
}
