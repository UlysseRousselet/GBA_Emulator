/*
** EPITECH PROJECT, 2024
** server
** File description:
** PlayerName
*/

/**
 * @file PlayerName.hpp
 * @brief Header file for the PlayerName component.
 *
 * This file defines the `PlayerName` structure, which is used to represent a player's
 * name in the game. It holds the font and text properties required for displaying
 * the player's name on the screen.
 */

#ifndef PLAYERNAME_HPP_
#define PLAYERNAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

/**
 * @struct PlayerName
 * @brief Represents the player's name display.
 *
 * This structure is used to manage the visual representation of a player's name in
 * the game. It contains the font to render the text and the `sf::Text` object for
 * rendering the name on the screen.
 */
struct PlayerName {
    std::shared_ptr<sf::Font> font; ///< Shared pointer to the font used for rendering the name.
    sf::Text sf_text;               ///< The `sf::Text` object that holds the player's name to be displayed.
};

#endif /* !PLAYERNAME_HPP_ */
