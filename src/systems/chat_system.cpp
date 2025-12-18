/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** chat_system
*/

#include "C_Systems.hpp"

void chat_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<MessageStorage_t> &messageStorage)
{
    static bool isChat = false;
    sf::Event event;
    std::shared_ptr<sf::RenderWindow> window = nullptr;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i].value().window;
            event = *windows[i].value().event;
            isChat = windows[i].value().isChat;
            break;
        }
    }

    for (size_t i = 0; i < messageStorage.size(); i++) {
        if (messageStorage[i].has_value()) {
            sf::Text text;
            sf::Font font;
            if (!font.loadFromFile("bin/assets/font.ttf")) {
                // Handle error
            }
            text.setFont(font);
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::White);
            text.setString(messageStorage[i].value().message);
            text.setPosition(10, 10);
            window->draw(text);
        }
    }
}