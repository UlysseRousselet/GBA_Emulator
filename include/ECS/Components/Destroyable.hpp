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
#ifndef DESTROYABLE_HPP_
#define DESTROYABLE_HPP_

#include <SFML/Graphics.hpp> ///< SFML graphics library for rendering and sprite management.
#include <iostream>          ///< For logging and debugging.
#include <memory>            ///< For managing shared pointers to textures.
#include <string>            ///< For handling strings, such as texture file names.

struct Destroyable {
    sf::Sprite sprite;         // The sprite to display
    std::shared_ptr<sf::Texture> texture;

    sf::IntRect frameRect;     // The initial frame rectangle (defines the sprite's dimensions)
    int frameCount;            // The number of frames in the animation
    int currentFrame;      // Current frame in the animation
    float frameDuration; // Time per frame for animation
    float elapsedTime;  // Time passed since last frame update
    bool isDestroyed = false;  // Flag to track whether the entity should be destroyed
};


#endif /* !DESTROYABLE_HPP_ */