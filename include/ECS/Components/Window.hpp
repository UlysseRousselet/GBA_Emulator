/*
** EPITECH PROJECT, 2024
** server
** File description:
** Window
*/

/**
 * @file Window.hpp
 * @brief Header file for the Window component.
 *
 * This file defines the `Window` structure, which represents the game window
 * and contains various properties and objects needed to manage and interact
 * with the window during gameplay, including handling events, tracking mouse
 * input, and managing the game state.
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_


#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @struct Window
 * @brief Represents the game window and its associated properties.
 *
 * The `Window` structure encapsulates the `sf::RenderWindow`, event handling,
 * clock management, mouse position tracking, and game state indicators. It is
 * used to manage window rendering, input, and state within the game.
 */
struct Window {
    std::shared_ptr<sf::RenderWindow> window; ///< The window object used for rendering the game.
    std::shared_ptr<sf::Event> event;         ///< The event object used to handle window events (e.g., keyboard, mouse).
    std::shared_ptr<sf::Clock> clock;         ///< The clock used for tracking elapsed time.
    float deltaTime;                          ///< The time passed between the current and last frame (in seconds).
    sf::Vector2u windowSize;
    bool isMenu;           ///< Indicates if the current screen is the menu.
    bool isChat;           ///< Indicates if the chat window is open.
    bool hasFocus;         ///< Indicates if the window is currently focused by the user.
    sf::Vector2f mousePos; ///< The current position of the mouse pointer in the window.
    bool hasClicked;       ///< Indicates if the mouse has been clicked.
    bool isGame;           ///< Indicates if the current screen is the game itself (as opposed to the menu).
    bool isSnake;          ///< Indicates if the game is in the snake game state.
    bool isLobby = false;
};

#endif /* !WINDOW_HPP_ */
