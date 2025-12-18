/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** sparses_array.hpp
*/

#ifndef ZIPPER
#define ZIPPER

#include "Zipper_iterator.hpp"
#include <tuple>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <utility>
#include <optional>
#include <functional>

template<class ...Containers>
class Zipper {
    public:
        using iterator = Zipper_iterator<Containers ...>;
        using iterator_tuple = typename iterator::iterator_tuple;
        Zipper(Containers &...cs) : _begin(std::begin(cs)...), _end(_compute_end(cs...)), _size(_compute_size(cs...)) {}
        iterator begin() { return iterator(_begin, _size); }
        iterator end() { return iterator(_end, _size); }
    private:
        static size_t _compute_size(Containers &...containers) {
            return std::min({std::distance(std::begin(containers), std::end(containers))...});
        }
        static iterator_tuple _compute_end(Containers &...containers) {
            return std::make_tuple(std::end(containers)...);
        }
    private :
        iterator_tuple _begin;
        iterator_tuple _end;
        size_t _size;
};

#endif
