/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

/**
 * @file C_Core.hpp
 * @brief Declaration of the Core class, managing the main game logic and loop.
 */
#ifndef C_CORE_HPP_
#define C_CORE_HPP_

#include "C_SceneManager.hpp"
#include "C_Systems.hpp"
#include "Registry.hpp"
#include <iostream>
#include <map>
#include <thread>
#include <fstream>

/**
 * @class Core
 * @brief Class responsible for managing the core game logic and lifecycle.
 */
class Core {
  public:
    /**
     * @brief Constructor of the Core class.
     *
     * Initializes the game with the necessary dependencies.
     * 
     * @param registry Shared pointer to the Registry object for managing entities.
     */
    Core(std::shared_ptr<Registry> registry, int ac, char ** av);

    /**
     * @brief Destructor of the Core class.
     *
     * Cleans up resources and ensures proper shutdown of the game systems.
     */
    ~Core();

    /**
     * @brief Starts the main game loop.
     *
     * This loop manages the progression of the game, including updating scenes,
     * processing input, and managing entities and systems.
     */
    void loop();

  protected:
    std::shared_ptr<Registry> registry; ///< Shared pointer to the Registry object for managing entities.
    SceneManager sceneManager;          ///< Object responsible for managing game scenes.
};

#endif /* !GAME_HPP_ */