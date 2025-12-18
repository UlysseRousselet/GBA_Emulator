/*
** EPITECH PROJECT, 2024
** B-CPP-500-PAR-5-2-rtype-ulysse.rousselet
** File description:
** control_system.hpp
*/

#include "C_Systems.hpp"

void uiHpBar_system(Registry &registry, Sparse_array<Window> &window, Sparse_array<UIHpBar> &uiHpBar)
{
    std::shared_ptr<sf::RenderWindow> win = nullptr;

    for (size_t i = 0; i < window.size(); i++) {
        if (window[i].has_value()) {
            win = window[i].value().window;
            break;
        }
    }
    for (size_t i = 0; i < uiHpBar.size(); i++) {
        if (uiHpBar[i].has_value()) {
            uiHpBar[i].value().rect.setPosition((uiHpBar[i]->pos.x), (uiHpBar[i]->pos.y));
            uiHpBar[i].value().rect.setSize(sf::Vector2f((uiHpBar[i]->size.x), (uiHpBar[i]->size.y)));
            uiHpBar[i].value().rectHp.setPosition((uiHpBar[i]->pos.x), (uiHpBar[i]->pos.y));
            uiHpBar[i].value().rectHp.setSize(sf::Vector2f((uiHpBar[i]->size.x * (uiHpBar[i]->hp / 100.0f)), (uiHpBar[i]->size.y)));
            uiHpBar[i].value().text.setPosition((uiHpBar[i]->pos.x + 10), (uiHpBar[i]->pos.y - 30));
            uiHpBar[i].value().text.setString(uiHpBar[i]->name + " : " + std::to_string(uiHpBar[i]->hp));
            uiHpBar[i].value().text.setFont(uiHpBar[i]->font);
            uiHpBar[i].value().text.setCharacterSize(20);
            uiHpBar[i].value().text.setFillColor(sf::Color::White);
            win->draw(uiHpBar[i]->rectHp);
            win->draw(uiHpBar[i]->rect);
            win->draw(uiHpBar[i]->text);
        }
    }
}
