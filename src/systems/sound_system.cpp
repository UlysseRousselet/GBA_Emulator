/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** position_system.hpp
*/

#include "C_Systems.hpp"
#include <SFML/Audio.hpp>

void sound_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Sound_rtype> &sound)
{
    (void)registry;
    float deltaTime = 0.0f;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            deltaTime = windows[i].value().deltaTime;
        }
    }

    for (size_t i = 0; i < sound.size(); i++) {
        auto &soundComponent = sound[i];

        if (soundComponent.has_value()) {
            auto &sound = soundComponent.value().sound;

            if (sound->getStatus() != sf::Sound::Playing && !soundComponent.value().played) {
                sound->play();
                soundComponent.value().played = true;
            }

            if (soundComponent.value().played && sound->getStatus() == sf::Sound::Stopped) {
                registry.kill_entity(registry.entity_from_index(i));
            }
        }
    }
}
