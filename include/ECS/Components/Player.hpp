/*
** EPITECH PROJECT, 2024
** server
** File description:
** Player
*/

/**
 * @file Player.hpp
 * @brief Header file for the Player component.
 *
 * This file defines the `Player` structure, which is used to represent a player in
 * the game. Each player has an ID and a health value, which are essential for
 * tracking the player's state within the game.
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <memory>
#include <string>

/**
 * @struct Player
 * @brief Represents a player in the game.
 *
 * This structure is used to store basic information about a player, such as their
 * unique ID and current health points (HP). This can be extended later to include
 * additional properties like position, inventory, etc.
 */
struct Player {
    int id; ///< The unique identifier for the player.
    int hp; ///< The health points of the player.
    std::string name; ///< The name of the player.
};

#endif /* !DRAWABLE_HPP_ */
