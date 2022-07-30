#include "game.hpp"

Game::Game(const int &width, const int &height)
    : width(width),
      height(height),
      player(Player(1, Vect2{(float)((float)width / 2.0f), (float)((float)height / 2.0f)}, sf::Color::White)) {}

void Game::step(const int &deltaTime, sf::RenderWindow &window)
{
    for (long long unsigned i = 0; i < enemies.size(); i++)
    {
        enemies[i].step(deltaTime);
        if (enemies[i].outside_window(width, height))
        {
            enemies.erase(enemies.begin() + i);
            i--;
        }
    }

    player.set_position(Vect2{(float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y});
}

void Game::draw(sf::RenderWindow &window) const
{
    for (long long unsigned i = 0; i < enemies.size(); i++)
    {
        enemies[i].draw(window);
    }
    player.draw(window);
}

Player Game::get_player() const
{
    return player;
}