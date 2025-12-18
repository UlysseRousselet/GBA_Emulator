/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** control_system.hpp
*/

#include "C_Systems.hpp"

void displayer_system(Registry &registry, Sparse_array<Window> &window)
{
    for (size_t i = 0; i < window.size(); i++) {
        if (window[i].has_value()) {
            window[i].value().window->display();
        }
    }
}
