/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** Registry.hpp
*/

/**
 * @file Registry.hpp
 * @brief Manages components and entities in the game, allowing component registration,
 *        entity spawning, and system execution.
 *
 * This file defines the `Registry` class, which serves as the core of the ECS (Entity-Component-System) framework.
 * The `Registry` allows for the registration, addition, removal, and retrieval of components associated with
 * entities. It also provides methods for entity management (spawning, killing) and running systems.
 */

#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "Components.hpp"
#include "Entity.hpp"
#include "Mod.hpp"
#include "Sparse_array.hpp"
#include "Zipper.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <any>
#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>

/**
 * @class Registry
 * @brief A class that manages entities and their components in the ECS system.
 *
 * The `Registry` class provides functionality to register and manage components, spawn and kill entities,
 * and execute systems. It allows you to associate components with entities, and manage the lifecycle of both.
 */
class Registry {
  public:
    /**
     * @brief Default constructor for the `Registry` class.
     * Initializes the registry with no components or entities.
     */
    Registry()
    {}

    /**
     * @brief Registers a component type with the registry.
     *
     * This method registers a component type in the registry, allowing it to store and manage instances of that component.
     *
     * @tparam Component The type of the component to register.
     * @return A reference to the `Sparse_array` that stores the components of the given type.
     */
    template <class Component> Sparse_array<Component> &register_component();

    /**
     * @brief Retrieves the components of a given type from the registry.
     *
     * This method returns a reference to the `Sparse_array` that contains components of the specified type.
     *
     * @tparam Component The type of the component to retrieve.
     * @return A reference to the `Sparse_array` that stores the components of the given type.
     */
    template <class Component> Sparse_array<Component> &get_components();

    /**
     * @brief Retrieves the components of a given type from the registry (const version).
     *
     * This method returns a const reference to the `Sparse_array` that contains components of the specified type.
     *
     * @tparam Component The type of the component to retrieve.
     * @return A const reference to the `Sparse_array` that stores the components of the given type.
     */
    template <class Component> Sparse_array<Component> const &get_components() const;

    /**
     * @brief Spawns a new entity.
     *
     * This method creates a new entity by either reusing a dead entity (if available) or incrementing the last entity ID.
     *
     * @return The newly spawned entity.
     */
    Entity spawn_entity()
    {
        if (!_dead_entities.empty()) {
            Entity entity = _dead_entities.back();
            _dead_entities.pop_back();
            return entity;
        }
        this->last_entity++;
        return Entity(this->last_entity);
    };

    size_t get_last_entity() const {
        return last_entity;
    }

    bool is_entity_dead(Entity const &entity) const {
        return std::find(_dead_entities.begin(), _dead_entities.end(), entity) != _dead_entities.end();
    }

    /**
     * @brief Retrieves an entity by its index.
     *
     * This method retrieves an entity from the registry using its index. If the index is invalid or the entity is dead,
     * it returns an invalid entity.
     *
     * @param idx The index of the entity.
     * @return The entity with the specified index.
     */
    Entity entity_from_index(size_t idx)
    {
        if (this->last_entity < idx)
            return Entity(-1);
        for (auto it : _dead_entities) {
            if (it == idx)
                return Entity(-1);
        }
        return Entity(idx);
    }

    /**
     * @brief Marks an entity as dead and removes it from the game.
     *
     * This method removes an entity from the game and adds it to the list of dead entities, making it available for reuse.
     * It also calls any registered entity erasers to clean up components associated with the entity.
     *
     * @param entity The entity to remove from the game.
     */
    void kill_entity(Entity const &entity)
    {
        _dead_entities.push_back(entity);
        for (auto it : _entity_erasers) {
            it.second(*this, entity);
        }
    }

    /**
     * @brief Finds an entity that holds a specified component.
     *
     * This method searches for an entity that contains the specified component and returns it.
     * If no such entity is found, it returns an invalid entity.
     *
     * @tparam Component The type of the component to search for.
     * @return The entity that contains the specified component.
     */
    template <typename Component> Entity find_entity_with_component()
    {
        auto it = get_components<Component>().begin();
        for (size_t i = 0; i < last_entity; i++) {
            if (it[i].has_value())
                return Entity(i);
        }
        return Entity(-1);
    }

    /**
     * @brief Finds an entity based on a player's ID.
     *
     * This method searches for an entity that represents a player with the specified ID.
     *
     * @param id The ID of the player.
     * @return The entity representing the player, or an invalid entity if not found.
     */
    Entity find_player_with_id(int id)
    {
        auto &it = get_components<Player>();
        for (size_t i = 0; i < it.size(); i++) {
            if (it[i].has_value() && it[i].value().id == id)
                return Entity(i);
        }
        return Entity(-1);
    }

    /**
     * @brief Adds a component to an entity.
     *
     * This method associates a specified component with a given entity, adding it to the registry.
     *
     * @tparam Component The type of the component to add.
     * @param to The entity to which the component will be added.
     * @param c The component to add to the entity.
     * @return A reference to the added component.
     */
    template <typename Component> typename Sparse_array<Component>::reference_type add_component(Entity const &to, Component &&c);

    /**
     * @brief Emplaces a component for an entity in the registry.
     *
     * This method constructs a component in place for a given entity, forwarding the provided parameters to the constructor.
     *
     * @tparam Component The type of the component to emplace.
     * @tparam Params The types of the parameters used to construct the component.
     * @param to The entity to which the component will be emplaced.
     * @param p The parameters used to construct the component.
     * @return A reference to the emplaced component.
     */
    template <typename Component, typename... Params>
    typename Sparse_array<Component>::reference_type emplace_component(Entity const &to, Params &&...p);

    /**
     * @brief Removes a component from an entity.
     *
     * This method removes a specified component from an entity, erasing it from the registry.
     *
     * @tparam Component The type of the component to remove.
     * @param from The entity from which the component will be removed.
     */
    template <typename Component> void remove_component(Entity const &from);

    /**
     * @brief Adds a system function that operates on specific components.
     *
     * This method registers a system function that operates on entities with specified components.
     * The function will be called during the system execution phase.
     *
     * @tparam Components The types of components that the system operates on.
     * @tparam Function The type of the system function.
     * @param f The system function to add.
     */
    template <class... Components, typename Function> void add_system(Function &&f);

    /**
     * @brief Adds a system function (const version) that operates on specific components.
     *
     * This method registers a system function that operates on entities with specified components.
     * The function will be called during the system execution phase.
     *
     * @tparam Components The types of components that the system operates on.
     * @tparam Function The type of the system function.
     * @param f The system function to add.
     */
    template <class... Components, typename Function> void add_system(Function const &f);

    /**
     * @brief Executes all system functions.
     *
     * This method runs all registered system functions. Each function operates on entities with specific components
     * and is executed during the system update phase.
     */
    void run_systems()
    {
        for (auto &f : this->_system_functions) {
            f();
        }
    }

  private:
    // Map of component arrays, keyed by type
    std::unordered_map<std::type_index, std::any> _components_arrays;
    // Map of functions for erasing an entity from all components
    std::unordered_map<std::type_index, std::function<void(Registry &, Entity const &)>> _entity_erasers;
    // Vector of system functions
    std::vector<std::function<void()>> _system_functions;

    // Last assigned entity ID
    size_t last_entity = 0;
    // List of dead entities available for reuse
    std::vector<Entity> _dead_entities;
};

#include "EntityManager.ipp"
#include "Registry.ipp"

#endif
