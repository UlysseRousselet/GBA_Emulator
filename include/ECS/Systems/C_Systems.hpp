/*
** EPITECH PROJECT, 2024
** server
** File description:
** Systems.hpp
*/

#ifndef SYSTEMS_HPP_
#define SYSTEMS_HPP_

#include "Registry.hpp"

void position_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Position> &position, Sparse_array<Velocity> &velocity);
void draw_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<Drawable> &drawable,
                 Sparse_array<DrawableSnake> drawableSnake);
void sound_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Sound_rtype> &sound);
void destroy_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Destroyable> &destroyable);
void menu_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Menu> &menu, Sparse_array<MenuButton> &menuButton);
void lobby_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Lobby> &lobby, Sparse_array<LobbyButton> &lobbyButton,
                  Sparse_array<LobbyBack> &lobbyBack, Sparse_array<LobbyText> &lobbyText);
void titlescreen_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<TitleScreen> &titleScreen);
void background_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Background> &background);
void clearer_system(Registry &registry, Sparse_array<Window> &window);
void displayer_system(Registry &registry, Sparse_array<Window> &window);
void particle_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<ParticleSystem> &particle);
void uiHpBar_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<UIHpBar> &uiHpBar);
void force_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Player> &players, Sparse_array<Force> &forces,
                  Sparse_array<Position> &position);
void charge_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<Charging> &charge, Sparse_array<Position> &position,
                   Sparse_array<Player> &player);
void wall_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Position> &position, Sparse_array<Wall> &wall,
                 Sparse_array<Drawable> &drawable, Sparse_array<Player> &player);
void chat_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<MessageStorage_t> &messageStorage);

#endif /* !SYSTEMS_HPP_ */