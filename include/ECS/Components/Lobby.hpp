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

#ifndef LOBBY_HPP_
#define LOBBY_HPP_

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
struct Lobby {
    sf::Sprite sprite;                    ///< The sprite that represents the menu on the screen.
    std::shared_ptr<sf::Texture> texture; ///< The texture associated with the menu sprite.
};

struct LobbyButton {
    sf::Sprite sprite;                         ///< The sprite representing the button in its normal state.
    std::shared_ptr<sf::Texture> texture;      ///< The texture associated with the button's normal sprite.
    sf::Sprite hoverSprite;                    ///< The sprite representing the button in its hover state.
    std::shared_ptr<sf::Texture> hoverTexture; ///< The texture associated with the button's hover sprite.
    sf::IntRect clickArea;                     ///< The rectangular area that defines the clickable region of the button.
    std::function<void(Registry &)> onClick;   ///< The action to perform when the button is clicked.
};

struct LobbyBack {
    sf::Sprite sprite;                    ///< The sprite representing the button in its normal state.
    std::shared_ptr<sf::Texture> texture; ///< The texture associated with the button's normal sprite.
};

struct LobbyText {
    sf::Text text;               ///< The SFML text object that represents the text.
    std::shared_ptr<sf::Font> font; ///< A shared pointer to the font used for the text.
};

#endif /* !SETTINGS_HPP_ */
