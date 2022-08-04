#include <SFML/graphics.hpp>
#include "game.hpp"

int main(int argc, char *args[])
{
    loadConfig();
    Game game(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

    sf::Font font;
    font.loadFromFile(FONTS_PATH + "arial.ttf");

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // Close window event
            case sf::Event::Closed:
                window.close();
                break;
            // Window lost focus - pause game
            case sf::Event::LostFocus:
                game.set_game_state(PAUSED);
                break;
            // Key pressed event
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                // Escape key - pause game
                case sf::Keyboard::Escape:
                    if (game.get_game_state() == RUNNING)
                        game.set_game_state(PAUSED);
                    else if (game.get_game_state() == PAUSED)
                        game.set_game_state(RUNNING);
                    break;
                // Space key - start|restart game
                case sf::Keyboard::Space:
                    if (game.get_game_state() == START_MENU || game.get_game_state() == GAME_OVER)
                        game.restart();
                    break;
                default:
                    break;
                }
            // Mouse button pressed event
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button)
                {
                // Left mouse button - start|restart|unpause game
                case sf::Mouse::Left:
                    if (game.get_game_state() == START_MENU || game.get_game_state() == GAME_OVER)
                        game.restart();
                    else if (game.get_game_state() == PAUSED)
                        game.set_game_state(RUNNING);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        window.clear();

        game.step(deltaClock.restart().asSeconds(), window);
        game.draw(window, font);

        window.display();
    }

    return 0;
}
