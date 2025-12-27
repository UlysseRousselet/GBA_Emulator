/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "C_Core.hpp"

void SceneManager::loadAllComponents()
{
    registry->register_component<Window>();

    registry->register_component<TitleScreen>();

    registry->register_component<Menu>();
    registry->register_component<MenuButton>();

    registry->register_component<Lobby>();
    registry->register_component<LobbyButton>();
    registry->register_component<LobbyBack>();
    registry->register_component<LobbyText>();

    registry->register_component<Background>();

    registry->register_component<Player>();
    registry->register_component<Boost>();
    registry->register_component<Monster>();
    registry->register_component<Bullet>();

    registry->register_component<Controllable>();
    registry->register_component<Velocity>();
    registry->register_component<Position>();

    registry->register_component<Drawable>();
    registry->register_component<Sound_rtype>();
    registry->register_component<Destroyable>();

    registry->register_component<PlayerName>();
    registry->register_component<MapSelected>();
    registry->register_component<ParticleSystem>();
    registry->register_component<UIHpBar>();
    registry->register_component<Force>();
    registry->register_component<Charging>();
    registry->register_component<Wall>();
    registry->register_component<DrawableSnake>();
    registry->register_component<Score>();
    registry->register_component<MessageStorage_t>();
    registry->register_component<Apple>();

    // créé direct l'entity qui contient la sfml
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "R-Type Client");
    window->setFramerateLimit(60);
    std::shared_ptr<sf::Event> event = std::make_shared<sf::Event>();
    std::shared_ptr<sf::Clock> clock = std::make_shared<sf::Clock>();
    Entity entityIndex = registry->spawn_entity();
    registry->add_component<Window>(registry->entity_from_index(entityIndex), Window{window, event, clock, 0.0f, sf::Vector2u(1280, 720)});
}

void SceneManager::loadAllSystems()
{
    registry->add_system<Window>(clearer_system);
    registry->add_system<Window, Background>(background_system);
    registry->add_system<Window, Menu, MenuButton>(menu_system);
    registry->add_system<Window, TitleScreen>(titlescreen_system);
    registry->add_system<Window, Lobby, LobbyButton, LobbyBack, LobbyText>(lobby_system);
    registry->add_system<Window, MessageStorage_t>(chat_system);
    registry->add_system<Window, Player, Force, Position>(force_system);
    registry->add_system<Window, Charging, Position, Player>(charge_system);
    registry->add_system<Window, Position, Velocity>(position_system);
    registry->add_system<Window, Position, Wall, Drawable, Player>(wall_system);
    registry->add_system<Window, Position, ParticleSystem>(particle_system);
    registry->add_system<Window, UIHpBar>(uiHpBar_system);
    registry->add_system<Window, Position, Drawable, DrawableSnake>(draw_system);
    registry->add_system<Window, Sound_rtype>(sound_system);
    registry->add_system<Window, Destroyable>(destroy_system);
    registry->add_system<Window>(displayer_system);
}
