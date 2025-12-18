/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** sparse_array.cpp
*/

#include "Sparse_array.hpp"

template<typename Component>
Sparse_array<Component>::Sparse_array()
{
}

template<typename Component>
Sparse_array<Component>::~Sparse_array()
{
}

template<typename Component>
Sparse_array<Component>::Sparse_array(Sparse_array const &other)
{
    _data = other._data;
}

template<typename Component>
Sparse_array<Component>::Sparse_array(Sparse_array &&other) noexcept
{
    _data = std::move(other._data);
}

template<typename Component>
Sparse_array<Component> &Sparse_array<Component>::operator=(Sparse_array const &other)
{
    _data = other._data;
    return *this;
}

template<typename Component>
Sparse_array<Component> &Sparse_array<Component>::operator=(Sparse_array &&other) noexcept
{
    _data = std::move(other._data);
    return *this;
}

template<typename Component>
typename Sparse_array<Component>::reference_type Sparse_array<Component>::operator[](size_t idx)
{
    return _data[idx];
}

template<typename Component>
typename Sparse_array<Component>::const_reference_type Sparse_array<Component>::operator[](size_t idx) const
{
    return _data[idx];
}

template<typename Component>
typename Sparse_array<Component>::iterator Sparse_array<Component>::begin()
{
    return _data.begin();
}

template<typename Component>
typename Sparse_array<Component>::const_iterator Sparse_array<Component>::begin() const
{
    return _data.begin();
}

template<typename Component>
typename Sparse_array<Component>::const_iterator Sparse_array<Component>::cbegin() const
{
    return _data.cbegin();
}

template<typename Component>
typename Sparse_array<Component>::iterator Sparse_array<Component>::end()
{
    return _data.end();
}

template<typename Component>
typename Sparse_array<Component>::const_iterator Sparse_array<Component>::end() const
{
    return _data.end();
}

template<typename Component>
typename Sparse_array<Component>::const_iterator Sparse_array<Component>::cend() const
{
    return _data.cend();
}

template<typename Component>
typename Sparse_array<Component>::size_type Sparse_array<Component>::size() const
{
    return _data.size();
}

template<typename Component>
typename Sparse_array<Component>::reference_type Sparse_array<Component>::insert_at(size_type pos, Component const &other)
{
    if (pos >= size())
        _data.resize(pos + 1);

    _data[pos] = other;

    return _data[pos];
}

template<typename Component>
typename Sparse_array<Component>::reference_type Sparse_array<Component>::insert_at(size_type pos, Component &&other)
{
    if (pos >= size())
        _data.resize(pos + 1);

    _data[pos] = std::move(other);

    return _data[pos];
}

template<typename Component>
template<class ... Params>
typename Sparse_array<Component>::reference_type Sparse_array<Component>::emplace_at(size_type pos, Params &&...params)
{
    if (pos >= size())
        _data.resize(pos + 1);

    auto& elem = _data[pos];

    std::allocator<value_type> allocator;

    if (elem.has_value()) {
        std::allocator_traits<std::allocator<value_type>>::destroy(allocator, &elem);
    }

    std::allocator_traits<std::allocator<value_type>>::construct(allocator, &elem, std::forward<Params>(params)...);

    return elem;
}

template<typename Component>
void Sparse_array<Component>::erase(size_type pos)
{
    if (pos >= size())
        return;

    _data[pos].reset();
}

template<typename Component>
typename Sparse_array<Component>::size_type Sparse_array<Component>::get_index(value_type const &other) const
{
    for (size_t i = 0; i < size(); i++) {
        std::cout << std::addressof(_data[i]) << "-" << std::addressof(other) << std::endl;
        if (std::addressof(_data[i]) == std::addressof(other)) {
            
            return i;
        }
    }

    throw std::runtime_error("Sparse_array::get_index: element not found");
}