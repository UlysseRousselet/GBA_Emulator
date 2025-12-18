/*
** EPITECH PROJECT, 2024
** server
** File description:
** Monster
*/

/**
 * @file Monster.hpp
 * @brief Header file for the Monster component.
 *
 * This file defines the `Monster` component, which represents a monster entity
 * in the game. The component holds the unique identifier for each monster.
 */

#ifndef MONSTER_HPP_
#define MONSTER_HPP_

/**
 * @struct Monster
 * @brief Represents a monster in the game.
 *
 * This structure is used to define a monster entity. It holds an ID that
 * uniquely identifies the monster. The ID can be used for tracking,
 * interaction, or other game logic related to monsters.
 */
struct Monster {
    int id; ///< The unique identifier for the monster.
};

#endif /* !BULLET_HPP_ */
