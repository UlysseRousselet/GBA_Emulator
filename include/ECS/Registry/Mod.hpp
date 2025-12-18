/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** Mod.hpp
*/

#ifndef MOD_HPP_
#define MOD_HPP_

#include "Components.hpp"
#include "Registry.hpp"
#include "Sparse_array.hpp"

class ISystemModule {
  public:
    virtual ~ISystemModule() = default;
    virtual void lib_system(Registry &registry, Sparse_array<Window> &window) = 0;
};

#endif /* !MOD_HPP_ */