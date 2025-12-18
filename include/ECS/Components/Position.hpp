/*
** EPITECH PROJECT, 2024
** server
** File description:
** Position
*/

/**
 * @file Position.hpp
 * @brief Header file for the Position component.
 *
 * This file defines the `Position` structure, which represents the position of an
 * object in a 2D space using x and y coordinates.
 */

#ifndef POSITION_HPP_
#define POSITION_HPP_

/**
 * @struct Position
 * @brief Represents the position of an object in a 2D space.
 *
 * This structure is used to store the x and y coordinates that define the position of
 * an object within the game's world or screen.
 */
struct Position {
    float x = 0; ///< The x-coordinate of the object's position.
    float y = 0; ///< The y-coordinate of the object's position.
};

#endif /* !POSITION_HPP_ */
