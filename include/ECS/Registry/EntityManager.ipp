/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** ManageEntity.ipp
*/

/**
 * @file ManageEntity.ipp
 * @brief Template functions for managing components in the `Registry` class.
 *
 * This file contains template functions that allow for adding, emplacing, and
 * removing components associated with entities in the registry. These functions
 * manipulate `Sparse_array` to store components for entities and provide
 * easy access to components based on their type.
 */

#include "Registry.hpp"

/**
 * @brief Adds a component to an entity in the registry.
 *
 * This function inserts a component into the registry for a specific entity.
 * It moves the given component into the registry to associate it with the entity.
 *
 * @tparam Component The type of the component to add.
 * @param to The entity to which the component will be added.
 * @param c The component to add to the entity.
 * @return The reference to the component associated with the entity.
 */
template <typename Component> typename Sparse_array<Component>::reference_type Registry::add_component(Entity const &to, Component &&c)
{
    get_components<Component>().insert_at(to, std::move(c)); // Insert the component
    return get_components<Component>()[to];                  // Return the reference to the added component
}

/**
 * @brief Emplaces a component for an entity in the registry.
 *
 * This function emplaces a component into the registry for a specific entity.
 * It forwards the provided parameters to construct the component in place for
 * the given entity.
 *
 * @tparam Component The type of the component to emplace.
 * @tparam Params The types of the parameters used to construct the component.
 * @param to The entity to which the component will be emplaced.
 * @param p The parameters used to construct the component.
 * @return The reference to the component associated with the entity.
 */
template <typename Component, typename... Params>
typename Sparse_array<Component>::reference_type Registry::emplace_component(Entity const &to, Params &&...p)
{
    get_components<Component>().emplace_at(to, std::forward<Params>(p)...); // Emplace the component
    return get_components<Component>()[to];                                 // Return the reference to the emplaced component
}

/**
 * @brief Removes a component from an entity in the registry.
 *
 * This function removes a component associated with an entity from the registry.
 *
 * @tparam Component The type of the component to remove.
 * @param from The entity from which the component will be removed.
 */
template <typename Component> void Registry::remove_component(Entity const &from)
{
    get_components<Component>().erase(from); // Erase the component for the given entity
}
