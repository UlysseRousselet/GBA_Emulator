/*
** EPITECH PROJECT, 2024
** server
** File description:
** UIHpBar
*/

/**
 * @file UIHpBar.hpp
 * @brief Header file for the UIHpBar component.
 *
 * This file defines the `UIHpBar` structure, which represents a health bar used in the user interface.
 */

#ifndef UIHPBAR_HPP_
#define UIHPBAR_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

/**
 * @struct UIHpBar
 * @brief Represents a rectangular shape in the user interface.
 *
 * The `UIHpBar` structure defines a health bar using SFML's `RectangleShape`. It
 * includes properties such as position, size, and health points (HP) to control the appearance of the
 * health bar within the UI.
 */
struct UIHpBar {
    sf::RectangleShape rect;   ///< The SFML `RectangleShape` that defines the appearance of the rectangle.
    sf::RectangleShape rectHp; ///< The SFML `RectangleShape` that defines the hp of the player.
    sf::Vector2f pos;          ///< The position of the rectangle in the UI.
    sf::Vector2f size;         ///< The size (width and height) of the rectangle.
    std::string name;          ///< The text to display the hp of the player.
    sf::Text text;             ///< The SFML `Text` object to display the name and HP of the player.
    sf::Font font;             ///< The font used to render the text.
    int hp;                    ///< The health points (HP) value represented by the bar.
};

#endif /* !UIRECT_HPP_ */
