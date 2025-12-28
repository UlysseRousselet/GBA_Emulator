/*
** EPITECH PROJECT, 2024
** server
** File description:
** SceneManager
*/

/**
 * @file C_SceneManager.hpp
 * @brief Declaration of the SceneManager class, which manages game scenes and components.
 */
#ifndef C_SCENEMANAGER_HPP_
#define C_SCENEMANAGER_HPP_

#include "Registry.hpp"
#include <iostream>
#include <map>
#include <thread>

/**
 * @class SceneManager
 * @brief Manages the various scenes and components of the game.
 */
class SceneManager {
  public:
    /**
     * @brief Constructs a SceneManager instance.
     *
     * Initializes the scene manager with the provided Asio and Registry objects.
     * 
     * @param registry Shared pointer to the Registry object for managing entities and components.
     */
    SceneManager(std::shared_ptr<Registry> registry, int ac, char** av) : registry(registry)
    {
      for (int i = 0; i < ac; i++) {
        roomFounds.push_back(av[i]);
      }
    }

    /**
     * @brief Destructor for the SceneManager class.
     */
    ~SceneManager()
    {}

    /**
     * @brief Loads all components required by the game.
     */
    void loadAllComponents();

    /**
     * @brief Loads all systems required by the game.
     */
    void loadAllSystems();

    void loadAllRooms();

  protected:
    std::vector<std::string> roomFounds;
    std::shared_ptr<Registry> registry; ///< Shared pointer to the Registry object for managing entities and components.
};

#endif /* !SCEENMANAGER_HPP_ */