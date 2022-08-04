#pragma once
#include <vector>
#include "player.hpp"
#include "enemy.hpp"
#include "config.hpp"

enum gameStates
{
    START_MENU,
    PAUSED,
    RUNNING,
    GAME_OVER
};

class Game
{
public:
    Game(const int &width, const int &height);

    void set_game_state(const gameStates &state);
    int get_game_state() const;
    Player get_player() const;

    void step(const float &deltaTime, sf::RenderWindow &window);
    void restart();
    void draw(sf::RenderWindow &window, sf::Font font);

protected:
    const int width;
    const int height;
    Player player;
    std::vector<Enemy> enemies;
    int gameState = START_MENU;
};