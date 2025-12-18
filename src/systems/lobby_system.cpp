/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** set_system.hpp
*/

#include "C_Systems.hpp"

void lobby_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Lobby> &lobby, Sparse_array<LobbyButton> &lobbyButton,
                  Sparse_array<LobbyBack> &lobbyBack, Sparse_array<LobbyText> &lobbyText)
{
    std::shared_ptr<sf::RenderWindow> window;
    bool isLobby;
    bool hasFocus;
    sf::Vector2f mousePos;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i].value().window;
            isLobby = windows[i].value().isLobby;
            hasFocus = windows[i].value().hasFocus;
            mousePos = windows[i].value().mousePos;
            break;
        }
    }

    if (!isLobby || !hasFocus)
        return;

    for (size_t i = 0; i < lobby.size(); i++) {
        auto &set = lobby[i];

        if (set.has_value()) {
            window->draw(set.value().sprite);
        }
    }

    for (size_t i = 0; i < lobbyBack.size(); i++) {
        auto &back = lobbyBack[i];

        if (back.has_value()) {
            window->draw(back.value().sprite);
        }
    }

    for (size_t i = 0; i < lobbyButton.size(); i++) {
        auto &button = lobbyButton[i];

        if (button.has_value()) {
            auto &buttonData = button.value();

            bool isHovered = buttonData.clickArea.contains(sf::Vector2i(mousePos));

            if (isHovered) {
                window->draw(buttonData.hoverSprite);
            } else {
                window->draw(buttonData.sprite);
            }

            static bool buttonClicked = false;

            if (isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !buttonClicked) {
                buttonData.onClick(registry);
                buttonClicked = true;
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                buttonClicked = false;
            }
        }
    }

    for (size_t i = 0; i < lobbyText.size(); i++) {
        auto &text = lobbyText[i];

        if (text.has_value()) {
            window->draw(text.value().text);
        }
    }
}