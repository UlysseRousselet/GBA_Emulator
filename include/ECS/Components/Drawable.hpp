/*
** EPITECH PROJECT, 2024
** server
** File description:
** Drawable
*/

/**
 * @file Drawable.hpp
 * @brief Header file for the Drawable component.
 *
 * This file defines the `Drawable` component, which is responsible for
 * representing drawable entities in the game world. These entities are
 * associated with a sprite and its corresponding texture, as well as
 * the animation properties that control how the sprite is rendered over time.
 *
 * @note This component is typically used for entities that require visual
 * representation in the game, such as characters, objects, or other animated
 * elements.
 */
#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include <SFML/Graphics.hpp> ///< SFML graphics library for rendering and sprite management.
#include <iostream>          ///< For logging and debugging.
#include <memory>            ///< For managing shared pointers to textures.
#include <string>            ///< For handling strings, such as texture file names.

struct Drawable {
    sf::Sprite sprite;                    ///< The sprite representing the drawable entity.
    std::shared_ptr<sf::Texture> texture; ///< Shared pointer to the texture associated with the sprite.

    sf::IntRect frameRect; ///< The rectangle defining the sprite's current frame for animation.
    int frameCount;        ///< The total number of frames in the sprite's animation.
    int currentFrame;      ///< The index of the current frame being displayed.
    float frameDuration;   ///< The duration each frame is displayed before switching.
    float elapsedTime;     ///< The accumulated time since the last frame switch.
    float damaged;
    float damageTimer = 0.0f;
    int frameYCount;
    int currentYFrame;
};

#endif /* !DRAWABLE_HPP_ */