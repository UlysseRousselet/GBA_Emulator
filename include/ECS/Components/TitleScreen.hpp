/*
** EPITECH PROJECT, 2024
** server
** File description:
** Menu
*/

/**
 * @file Menu.hpp
 * @brief Header file for the Menu component.
 *
 * This file defines the `Menu` component, which holds information about
 * the graphical elements of a menu in the game, including the sprite and
 * its associated texture. This component is used to display the menu screen
 * in the game, allowing the user to interact with various menu options.
 */

#ifndef TITLESCREEN_HPP_
#define TITLESCREEN_HPP_

#include <SFML/Graphics.hpp> ///< SFML graphics library for handling sprites and textures.
#include <functional>        ///< For defining callback functions to handle button clicks.
#include <iostream>          ///< For I/O operations (though not directly used here).
#include <memory>            ///< For managing shared pointers (used for textures).
#include <string>            ///< For handling strings (though not directly used here).

class Registry;

/**
 * @struct Menu
 * @brief Represents a menu in the game with its graphical elements.
 *
 * This structure holds the sprite and its associated texture for rendering
 * the menu on the screen. It can be used to manage and display various
 * menus, such as the main menu or pause menu.
 */
struct TitleScreen {
    sf::Sprite sprite;                    ///< The sprite that represents the menu on the screen.
    std::shared_ptr<sf::Texture> texture; ///< The texture associated with the menu sprite.
    sf::Text text;                        ///< The SFML text object that represents the text.
    std::shared_ptr<sf::Font> font;
    sf::RectangleShape inputArea;
    std::function<void(Registry &)> onClick;
    std::string playerName = "";
};

#endif /* !SETTINGS_HPP_ */
