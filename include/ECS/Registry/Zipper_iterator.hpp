/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** sparses_array.hpp
*/

#ifndef ZIPPER_ITERATOR
#define ZIPPER_ITERATOR

#include <tuple>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <utility>
#include <optional>
#include <functional>

template <class ...Containers>
class Zipper;

template <class ...Containers>
class Zipper_iterator {
        template <class Container>
        using iterator_t = decltype(std::declval<Container>().begin());
        template <class Container>
        using it_reference_t = typename iterator_t<Container>::reference;
    public:
        using value_type = std::tuple<it_reference_t<Containers>...>;
        using reference = value_type;
        using pointer = void;
        using difference_type = size_t;
        using iterator_category = std::forward_iterator_tag;
        using iterator_tuple = std::tuple<iterator_t<Containers>...>;
        friend Zipper<Containers...>;
        Zipper_iterator(iterator_tuple const &it_tuple, size_t max) {
            _current = it_tuple;
            _max = max;
            _idx = 0;
        }
    public:
        Zipper_iterator(Zipper_iterator const &z) {_current = z._current;_max = z._max;_idx = z._idx;}
        Zipper_iterator operator ++() { incr_all(_seq); return *this; }
        Zipper_iterator &operator++(int) { incr_all(_seq); return *this; }
        value_type operator*() { return to_value(_seq); }
        value_type operator->() { return to_value(_seq); }
        friend bool operator==(Zipper_iterator const & lhs, Zipper_iterator const &rhs) { return lhs._idx == rhs._idx; }
        friend bool operator!=(Zipper_iterator const & lhs , Zipper_iterator const& rhs) { return lhs._idx != rhs._idx; }
    private:
        template<size_t...Is>
        void incr_all(std::index_sequence<Is ...>) { ((std::get<Is>(_current)++, ...)); _idx++; }
        template<size_t ...Is>
        bool all_set(std::index_sequence<Is...>) { return ((std::get<Is>(_current) != std::end(std::get<Is>(_current))) &&...); }
        template<size_t ...Is>
        value_type to_value(std::index_sequence<Is...>) { return std::tie(*std::get<Is>(_current)...); }
    private:
        iterator_tuple _current;
        size_t _max;
        size_t _idx;
        static constexpr std::index_sequence_for<Containers...>_seq{};
};

#endif
