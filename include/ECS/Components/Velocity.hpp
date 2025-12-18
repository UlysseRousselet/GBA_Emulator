/*
** EPITECH PROJECT, 2024
** server
** File description:
** Velocity
*/

/**
 * @file Velocity.hpp
 * @brief Header file for the Velocity component.
 *
 * This file defines the `Velocity` structure, which represents the velocity
 * of an object in a 2D space. The structure includes the current speed in the
 * x and y directions, as well as factors that modify the object's speed.
 */

#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

/**
 * @struct Velocity
 * @brief Represents the velocity of an object in a 2D space.
 *
 * The `Velocity` structure holds the velocity components in the x and y
 * directions, as well as parameters for base speed and speed multiplier,
 * allowing for dynamic adjustments to the object's movement.
 */
struct Velocity {
    float x = 0;                  ///< The velocity in the x direction (horizontal).
    float y = 0;                  ///< The velocity in the y direction (vertical).
    float baseSpeed = 1.0f;       ///< The base speed of the object.
    float multiplierSpeed = 1.0f; ///< A multiplier applied to the base speed to adjust the object's movement.
};

#endif /* !VELOCITY_HPP_ */
