/*
** EPITECH PROJECT, 2024
** server
** File description:
** Game
*/

/**
 * @file C_Game.hpp
 * @brief Declaration of the Game class, managing the main game logic and loop.
 */
#ifndef C_GAME_HPP_
#define C_GAME_HPP_

#include "C_SceneManager.hpp"
#include "C_Systems.hpp"
#include "Registry.hpp"
#include <iostream>
#include <map>
#include <thread>

/**
 * @class Game
 * @brief Class responsible for managing the core game logic and lifecycle.
 */
class Game {
  public:
    /**
     * @brief Constructor of the Game class.
     *
     * Initializes the game with the necessary dependencies, including
     * network communication and entity management systems.
     *
     * @param asio Shared pointer to the C_Asio object for handling network communication.
     * @param registry Shared pointer to the Registry object for managing entities.
     */
    Game(std::shared_ptr<Registry> registry);

    /**
     * @brief Destructor of the Game class.
     *
     * Cleans up resources and ensures proper shutdown of the game systems.
     */
    ~Game();

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