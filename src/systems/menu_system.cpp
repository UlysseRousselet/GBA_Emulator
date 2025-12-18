/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** set_system.hpp
*/

#include "C_Systems.hpp"

void menu_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<Menu> &menu, Sparse_array<MenuButton> &menuButton)
{
    std::shared_ptr<sf::RenderWindow> window;
    bool isMenu;
    sf::Vector2f mousePos;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i]->window;
            isMenu = windows[i]->isMenu;
            mousePos = windows[i]->mousePos;
            break;
        }
    }

    if (!isMenu)
        return;

    for (size_t i = 0; i < menu.size(); i++) {
        auto &set = menu[i];

        if (set.has_value()) {
            window->draw(set.value().sprite);
        }
    }

    for (size_t i = 0; i < menuButton.size(); i++) {
        auto &button = menuButton[i];

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
}