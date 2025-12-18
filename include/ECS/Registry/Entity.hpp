/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** entity.hpp
*/

/**
 * @file entity.hpp
 * @brief Header file defining the `Entity` class.
 *
 * This file defines the `Entity` class, which represents an entity with
 * a unique identifier in the registry. The `Entity` class is used within
 * the game system to track and interact with various game objects.
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <vector>

/**
 * @class Entity
 * @brief Represents an entity in the game with a unique identifier.
 *
 * The `Entity` class encapsulates a unique identifier for each entity,
 * which allows it to be tracked and interacted with in the game system.
 */
class Entity {
  public:
    /**
     * @brief Constructor that initializes the entity with a unique ID.
     * @param id A unique identifier for the entity.
     */
    explicit Entity(size_t id)
    {
        _id = id;
    }

    /**
     * @brief Destructor for the Entity class.
     */
    ~Entity()
    {}

    /**
     * @brief Implicit conversion operator to retrieve the entity's ID.
     * @return The entity's unique ID as a size_t.
     */
    operator size_t()
    {
        return _id;
    }

    /**
     * @brief Implicit conversion operator to retrieve the entity's ID (const version).
     * @return The entity's unique ID as a size_t.
     */
    operator size_t() const
    {
        return _id;
    }

  private:
    size_t _id; /**< The unique identifier for the entity. */
};

#endif
