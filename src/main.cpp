#include <SFML/graphics.hpp>
#include "game.hpp"

const float FPS = 60.0f;
const int HEIGHT = 480, WIDTH = 640;

int main(int argc, char *args[])
{
    Game game(WIDTH, HEIGHT);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        game.step(deltaClock.restart().asSeconds(), window);
        game.draw(window);

        window.display();
    }

    return 0;
}
