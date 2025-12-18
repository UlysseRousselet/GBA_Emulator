/*
** EPITECH PROJECT, 2024
** server
** File description:
** Velocity
*/

#include <SFML/Audio.hpp>
#include <iostream> ///< For logging and debugging.
#include <memory>   ///< For managing shared pointers to textures.
#include <string>

/**
 * @file Velocity.hpp
 * @brief Header file for the Velocity component.
 *
 * This file defines the `Velocity` structure, which represents the velocity
 * of an object in a 2D space. The structure includes the current speed in the
 * x and y directions, as well as factors that modify the object's speed.
 */

#ifndef SOUND_HPP_
#define SOUND_HPP_

/**
 * @struct Velocity
 * @brief Represents the velocity of an object in a 2D space.
 *
 * The `Velocity` structure holds the velocity components in the x and y
 * directions, as well as paramet#include <iostream>          ///< For logging and debugging.
#include <memory>            ///< For managing shared pointers to textures.
#include <string> ers for base speed and speed multiplier,
 * allowing for dynamic adjustments to the object's movement.
 */
struct Sound_rtype {
    std::shared_ptr<sf::Sound> sound;
    std::shared_ptr<sf::SoundBuffer> buffer;
    bool played;
};

#endif /* !VELOCITY_HPP_ */
