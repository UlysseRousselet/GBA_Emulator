/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** sparses_array.hpp
*/

#ifndef SPARSE_ARRAY
#define SPARSE_ARRAY

#include <iostream>
#include <optional>
#include <vector>

template <typename Component> class Sparse_array {
  public:
    using value_type = std::optional<Component>;
    using reference_type = value_type &;
    using const_reference_type = value_type const &;
    using container_t = std::vector<value_type>;
    using size_type = typename container_t::size_type;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

    Sparse_array();
    Sparse_array(Sparse_array const &);
    Sparse_array(Sparse_array &&) noexcept;
    ~Sparse_array();
    Sparse_array &operator=(Sparse_array const &);
    Sparse_array &operator=(Sparse_array &&) noexcept;
    reference_type operator[](size_t idx);
    const_reference_type operator[](size_t idx) const;
    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;
    iterator end();
    const_iterator end() const;
    const_iterator cend() const;
    size_type size() const;
    reference_type insert_at(size_type pos, Component const &);
    reference_type insert_at(size_type pos, Component &&);
    template <class... Params> reference_type emplace_at(size_type pos, Params &&...);
    void erase(size_type pos);
    size_type get_index(value_type const &) const;

  private:
    container_t _data;
};

#include "Sparse_array.ipp"

#endif