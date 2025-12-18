/*
** EPITECH PROJECT, 2024
** server
** File description:
** MapSelected
*/

/**
 * @file MapSelected.hpp
 * @brief Header file for the MapSelected component.
 *
 * This file defines the `MapSelected` component, which holds information
 * about the currently selected map in the game. It is used to track the
 * user's or game's choice of map, allowing the game to load and display
 * the correct map during gameplay.
 */

#ifndef MAPSELECTED_HPP_
#define MAPSELECTED_HPP_

#include <SFML/Graphics.hpp> ///< SFML graphics library, although not directly used in this structure.
#include <memory>            ///< For managing shared pointers, although not directly used in this structure.

struct MapSelected {
    int mapSelected; ///< The ID or index of the currently selected map.
};

#endif /* !MAPSELECTED_HPP_ */
