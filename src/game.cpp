#include "game.hpp"

Game::Game(const int &width, const int &height)
    : width(width),
      height(height),
      player(Player(1, Vect2{(float)((float)width / 2), (float)((float)height / 2)}, sf::Color::White)) {}

void Game::step(const float &deltaTime, sf::RenderWindow &window)
{
    if (enemies.size() < 30)
    {
        float playerRadius = player.get_radius();
        enemies.push_back(Enemy::gen_rand_enemy(width, height, playerRadius - 10, playerRadius + 40));
    }

    for (long long unsigned i = 0; i < enemies.size(); i++)
    {
        enemies[i].step(deltaTime);
        if (enemies[i].outside_window(width, height))
        {
            enemies.erase(enemies.begin() + i);
            i--;
        }
    }

    player.set_mouse_position(width, height, window);
}

void Game::draw(sf::RenderWindow &window)
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