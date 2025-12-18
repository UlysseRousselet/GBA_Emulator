/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** draw_system.hpp
*/

#include "C_Systems.hpp"

void draw_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<Drawable> &drawable, Sparse_array<DrawableSnake> drawableSnake)
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

    for (size_t i = 0; i < drawableSnake.size(); i++) {
        auto &draw_snake = drawableSnake[i];

        if (draw_snake.has_value()) {
            auto &segments = draw_snake.value().segments;
            auto &positions = draw_snake.value().positions;
            sf::Color color = draw_snake.value().color;

            for (size_t j = 0; j < segments.size(); j++) {
                segments[j].setPosition(positions[j]);
                segments[j].setFillColor(color);
                window->draw(segments[j]);
            }
        }
    }

    for (size_t i = 0; i < position.size() && i < drawable.size(); i++) {
        auto &pos = position[i];
        auto &draw = drawable[i];

        if (pos.has_value() && draw.has_value()) {
            auto &sprite = draw.value().sprite;
            auto &frameRect = draw.value().frameRect;
            auto &frameCount = draw.value().frameCount;
            auto &elapsedTime = draw.value().elapsedTime;
            auto &currentFrame = draw.value().currentFrame;
            auto &frameDuration = draw.value().frameDuration;
            auto &damaged = draw.value().damaged;
            auto &damageTimer = draw.value().damageTimer;
            auto &currentY = draw.value().currentYFrame;
            auto &frameYCount = draw.value().frameYCount;

            sprite.setPosition(pos.value().x, pos.value().y);

            if (damaged > 0) {
                damageTimer += deltaTime;
                if (damageTimer >= 0.1f) {
                    if (sprite.getColor().a == 128) {
                        sprite.setColor(sf::Color(255, 255, 255, 255)); // Normal
                    } else {
                        sprite.setColor(sf::Color(255, 255, 255, 128)); // Translucide
                    }
                    damageTimer = 0.0f;
                }
                damaged -= deltaTime;
            } else {
                sprite.setColor(sf::Color(255, 255, 255, 255));
            }

            if (frameCount > 1) {
                // animation du sprite
                elapsedTime += deltaTime;

                if (elapsedTime >= frameDuration) {
                    currentFrame = (currentFrame + 1) % draw.value().frameCount;
                    sf::IntRect currentRect(frameRect.left + frameRect.width * currentFrame, frameRect.top + frameRect.height * currentY,
                                            frameRect.width, frameRect.height);
                    sprite.setTextureRect(currentRect);

                    elapsedTime = 0.0f;
                    if (currentFrame == frameCount - 1 && frameYCount > 1) {
                        currentY += 1;
                    }
                    if (currentY == frameYCount) {
                        currentY = 0;
                    }
                }
            }

            window->draw(sprite);
        }
    }
}