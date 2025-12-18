/*
** EPITECH PROJECT, 2024
** server
** File description:
** DrawableSnake
*/

#ifndef DRAWABLESNAKE_HPP_
#define DRAWABLESNAKE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

/**
 * @struct DrawableSnake
 * @brief Structure representing a drawable object in the game.
 *
 * This structure contains the graphical representation of an object, represented
 * by a rectangle shape (`sf::RectangleShape`) and its bounding box (`sf::FloatRect`).
 * It is typically used for game objects that can be rendered to the screen.
 */

struct DrawableSnake{
    std::vector<sf::CircleShape> segments;
    std::vector<sf::Vector2f> positions;
    sf::Color color;
    bool isAlive;
    float radius;
    float initialX;
    float initialY;
};

#endif /* !DRAWABLESNAKE_HPP_ */