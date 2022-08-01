#pragma once
#include <vector>
#include "player.hpp"
#include "enemy.hpp"

class Game
{
public:
    Game(const int &width, const int &height);
    Player get_player() const;

    void step(const float &deltaTime, sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

protected:
    const int width;
    const int height;
    Player player;
    std::vector<Enemy> enemies;
};