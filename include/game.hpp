#pragma once
#include <vector>
#include "player.hpp"
#include "enemy.hpp"

class Game
{
public:
    Game(const int &width, const int &height);
    void step(const int &deltaTime, sf::RenderWindow &window);
    void draw(sf::RenderWindow &window) const;
    Player get_player() const;

protected:
    const int width;
    const int height;
    Player player;
    std::vector<Enemy> enemies;
};