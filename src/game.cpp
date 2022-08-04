#include "game.hpp"
#include <string>

Game::Game(const int &width, const int &height)
    : width(width),
      height(height),
      player(Player(1, Vect2{0.0f, 0.0f}, sf::Color::White)) {}

void Game::step(const float &deltaTime, sf::RenderWindow &window)
{
    // Don't do anything if the game is paused
    if (gameState == PAUSED)
        return;

    // Spawns new enemies if needed
    if (gameState == RUNNING || gameState == START_MENU)
    {
        if (enemies.size() < ENEMY_COUNT)
        {
            float playerRadius = player.get_radius();
            enemies.push_back(Enemy::gen_rand_enemy(width, height, playerRadius - ENEMY_SIZE_PLAYER_MINUS, playerRadius + ENEMY_SIZE_PLAYER_PLUS));
        }
    }

    if (gameState != PAUSED)
    {
        // Updates all enemies
        for (long long unsigned i = 0; i < enemies.size(); i++)
        {
            enemies[i].step(deltaTime);
            if (enemies[i].outside_window(width, height))
            {
                enemies.erase(enemies.begin() + i);
                i--;
            }
        }
    }

    if (gameState == RUNNING)
    {
        // Moves the player to the location of the cursor
        player.set_mouse_position(width, height, window);
        // Checking for collisions between the player and the enemies
        const float playerLeft = player.get_position().x - player.get_radius();
        const float playerRight = player.get_position().x + player.get_radius();
        for (long long unsigned i = 0; i < enemies.size(); i++)
        {
            // Sweep and prune algorithm along the x-axis
            if (enemies[i].sweep_prune_x(playerLeft, playerRight))
            {
                // Regular collision check
                if (enemies[i].is_colliding(player))
                {
                    // If the enemy is smaller than the player, the player eats it and grows
                    if (player.get_radius() >= enemies[i].get_radius())
                    {
                        player.set_radius(player.get_radius() + 1);
                        enemies.erase(enemies.begin() + i);
                        i--;
                    }
                    // If the player is smaller than the enemy, he dies
                    else
                    {
                        gameState = GAME_OVER;
                        return;
                    }
                }
            }
        } // That's quite a lot of nested ifs, I know.
    }
}

void Game::restart()
{
    player.set_radius(1);
    enemies.clear();
    gameState = RUNNING;
}

void Game::draw(sf::RenderWindow &window, sf::Font font)
{
    // Draws all the enemies onto the screen
    for (long long unsigned i = 0; i < enemies.size(); i++)
    {
        enemies[i].draw(window);
    }

    switch (gameState)
    {
    case START_MENU:
    {
        // Draw the start menu
        sf::Text startMenu;
        startMenu.setFont(font);
        startMenu.setCharacterSize(WIDTH / 17.5f);
        startMenu.setString("Press space to start");
        startMenu.setPosition(width / 2 - startMenu.getLocalBounds().width / 2, height / 2 - startMenu.getLocalBounds().height / 2);
        window.draw(startMenu);
        break;
    }
    case RUNNING:
    {
        // Draws the player
        player.draw(window);
        break;
    }
    case PAUSED:
    {
        // Draws the pause menu
        sf::Text pausedMenu;
        pausedMenu.setFont(font);
        pausedMenu.setCharacterSize(WIDTH / 17.5f);
        pausedMenu.setString("PAUSED");
        pausedMenu.setPosition(width / 2 - pausedMenu.getLocalBounds().width / 2, height / 2 - pausedMenu.getLocalBounds().height / 2);
        window.draw(pausedMenu);
        break;
    }
    case GAME_OVER:
        // Draws the game over menu
        sf::Text gameOver;
        gameOver.setFont(font);
        gameOver.setCharacterSize(WIDTH / 10);
        gameOver.setString("Game over!");
        gameOver.setPosition(width / 2 - gameOver.getLocalBounds().width / 2, height / 2 - gameOver.getLocalBounds().height * 2);
        window.draw(gameOver);

        sf::Text score;
        score.setFont(font);
        score.setCharacterSize(WIDTH / 17.5f);
        score.setString("Score: " + std::to_string((int)player.get_radius()));
        score.setPosition(width / 2 - score.getLocalBounds().width / 2, height / 2 - score.getLocalBounds().height / 2);
        window.draw(score);

        sf::Text restart;
        restart.setFont(font);
        restart.setCharacterSize(WIDTH / 17.5f);
        restart.setString("Press space to respawn");
        restart.setPosition(width / 2 - restart.getLocalBounds().width / 2, height / 2 + restart.getLocalBounds().height * 2);
        window.draw(restart);
        break;
    }
}

Player Game::get_player() const
{
    return player;
}

void Game::set_game_state(const gameStates &state)
{
    gameState = state;
}

int Game::get_game_state() const
{
    return gameState;
}