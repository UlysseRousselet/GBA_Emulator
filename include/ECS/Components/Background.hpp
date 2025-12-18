/*
** EPITECH PROJECT, 2024
** server
** File description:
** Background
*/

/**
 * @file Background.hpp
 * @brief Header file for the Background component.
 *
 * This file defines the `Background` component, which is responsible for
 * representing drawable entities in the game world. These entities are
 * associated with a sprite and its corresponding texture, as well as
 * the animation properties that control how the sprite is rendered over time.
 *
 * @note This component is typically used for entities that require visual
 * representation in the game, such as characters, objects, or other animated
 * elements.
 */
#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_

#include <SFML/Graphics.hpp> ///< SFML graphics library for rendering and sprite management.
#include <iostream>          ///< For logging and debugging.
#include <memory>            ///< For managing shared pointers to textures.
#include <string>            ///< For handling strings, such as texture file names.

struct Background {
    sf::Sprite sprite;                  ///< The sprite representing the drawable entity.
    sf::Sprite sprite2;                 ///< The sprite representing the drawable entity.
    std::shared_ptr<sf::Texture> texture; ///< Shared pointer to the texture associated with the sprite.
};

#endif /* !BACKGROUND_HPP_ */