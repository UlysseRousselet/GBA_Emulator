#include "C_Systems.hpp"

void titlescreen_system(Registry &registry, Sparse_array<Window> &windows, Sparse_array<TitleScreen> &titleScreen)
{
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<sf::Event> event;
    bool isLobby;
    bool isGame;
    bool hasFocus = false;

    for (size_t i = 0; i < windows.size(); i++) {
        if (windows[i].has_value()) {
            window = windows[i]->window;
            event = windows[i]->event;
            isLobby = windows[i]->isLobby;
            isGame = windows[i]->isGame;
            hasFocus = windows[i]->hasFocus;
            break;
        }
    }

    if (isLobby || isGame)
        return;

    static bool enterPressed = false;
    static bool keyPressed = false;

    for (size_t i = 0; i < titleScreen.size(); i++) {
        auto &set = titleScreen[i];

        if (titleScreen[i].has_value()) {
            // Handle typing and updating playerName
            if (event->type == sf::Event::TextEntered && hasFocus) {
                if (!keyPressed) {
                    if (event->text.unicode == 8) { // Backspace
                        if (!set.value().playerName.empty()) {
                            set.value().playerName.pop_back();
                        }
                    } else if (event->text.unicode < 128) { // Printable ASCII characters
                        set.value().playerName += static_cast<char>(event->text.unicode);
                    }
                    keyPressed = true;
                }
            }

            if (event->type == sf::Event::KeyReleased) {
                keyPressed = false;
            }

            // Trigger onClick function when Enter key is pressed
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && hasFocus) {
                if (!enterPressed) {
                    std::cout << "Return pressed" << std::endl;
                    if (set.value().onClick) {
                        set.value().onClick(registry);
                    }
                    enterPressed = true;
                }
            } else {
                enterPressed = false;
            }

            // Update the text object to display the current player name
            set.value().text.setString(set.value().playerName);

            // Draw the TitleScreen elements
            window->draw(set.value().sprite);
            window->draw(set.value().inputArea);
            window->draw(set.value().text);
        }
    }
}
