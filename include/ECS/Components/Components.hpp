/*
** EPITECH PROJECT, 2024
** server
** File description:
** Components
*/

/**
 * @file Components.hpp
 * @brief Header file that includes all component headers for the game.
 *
 * This file serves as an umbrella for all individual component definitions used
 * within the game’s entity-component system (ECS). It includes various components
 * that represent different aspects of the game entities, such as visual, physical,
 * and gameplay-related properties.
 */
#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include "Background.hpp"
#include "Boost.hpp"
#include "Bullet.hpp" ///< Component for handling bullet entities.
#include "Charging.hpp"
#include "Controllable.hpp" ///< Component for handling player control inputs.
#include "Destroyable.hpp"  ///< Component for managing entities that can be destroyed.
#include "Drawable.hpp"     ///< Component for rendering entities to the screen.
#include "DrawableSnake.hpp"
#include "Force.hpp" ///< Component for managing the force of entities.
#include "Lobby.hpp"
#include "MapSelected.hpp" ///< Component for tracking the selected map in the game.
#include "Menu.hpp"        ///< Component for managing menu-related data.
#include "Message.hpp"
#include "Monster.hpp"        ///< Component for managing monster-related data.
#include "ParticleSystem.hpp" ///< Component for handling particle effects.
#include "Player.hpp"         ///< Component for managing player-related data.
#include "PlayerName.hpp"     ///< Component for managing player names.
#include "Position.hpp"       ///< Component for storing the position of entities.
#include "Score.hpp"
#include "Sound.hpp" ///< Component for handling window-related data and state.
#include "TitleScreen.hpp"
#include "UIHpBar.hpp"  ///< Component for managing health bars in the UI.
#include "Velocity.hpp" ///< Component for managing the velocity of entities.
#include "Wall.hpp"     ///< Component for managing wall entities.
#include "Window.hpp"   ///< Component for handling window-related data and state.
#include "Apple.hpp"

#endif /* !COMPONENTS_HPP_ */