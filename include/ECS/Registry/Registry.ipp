/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** Registry.ipp
*/

#include "Registry.hpp"

template <class Component> Sparse_array<Component> &Registry::register_component()
{
    auto type = std::type_index(typeid(Component));
    if (_components_arrays.find(type) == _components_arrays.end()) {
        _components_arrays[type] = Sparse_array<Component>();

        _entity_erasers[type] = [](Registry &registry, Entity const &entity) { registry.get_components<Component>().erase(entity); };
    }
    return std::any_cast<Sparse_array<Component> &>(_components_arrays[type]);
}

template <class Component> Sparse_array<Component> &Registry::get_components()
{
    auto type = std::type_index(typeid(Component));
    return std::any_cast<Sparse_array<Component> &>(_components_arrays[type]);
}

template <class Component> Sparse_array<Component> const &Registry::get_components() const
{
    auto type = std::type_index(typeid(Component));
    return std::any_cast<Sparse_array<Component> const &>(_components_arrays.at(type));
}

template <class... Components, typename Function> void Registry::add_system(Function &&f)
{
    this->_system_functions.push_back([this, f = std::forward<Function>(f)]() { f(*this, this->get_components<Components>()...); });
}

template <class... Components, typename Function> void Registry::add_system(Function const &f)
{
    this->_system_functions.push_back([this, f = f]() { f(*this, this->get_components<Components>()...); });
}
