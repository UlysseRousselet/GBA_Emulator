/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** Force.hpp
*/

#ifndef FORCE_HPP_
#define FORCE_HPP_

#include <iostream>
#include <memory>
#include <string>

/**
 * @struct Force
 * @brief Structure representing the force of in the game.
 *
 * This structure holds the basic properties of a force, such as its unique identifier,
 * damage dealt to players, and its health points (HP). It can be extended to include other
 */
struct Force {
    bool snapped;
    int playerId;
};

#endif /* !DRAWABLE_HPP_ */
