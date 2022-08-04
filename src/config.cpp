#include "config.hpp"

#include <fstream>

std::string FONTS_PATH;
float FPS;
int WIDTH, HEIGHT;
int unsigned ENEMY_COUNT;
int ENEMY_SIZE_PLAYER_MINUS, ENEMY_SIZE_PLAYER_PLUS;
int ENEMY_SPEED_BASE, ENEMY_SPEED_PLUS_RANDOM;

void loadConfig()
{
    // Loads the config file
    std::ifstream configFile("config.cfg");

    // Sets the values of the config variables
    std::string line;
    while (std::getline(configFile, line))
    {
        std::string param = line.substr(0, line.find("=") - 1);
        std::string value = line.substr(line.find("=") + 2);

        if (param == "FONTS_PATH")
            FONTS_PATH = value;
        else if (param == "FPS")
            FPS = stof(value);
        else if (param == "WIDTH")
            WIDTH = stoi(value);
        else if (param == "HEIGHT")
            HEIGHT = stoi(value);
        else if (param == "ENEMY_COUNT")
            ENEMY_COUNT = stoi(value);
        else if (param == "ENEMY_SIZE_PLAYER_MINUS")
            ENEMY_SIZE_PLAYER_MINUS = stoi(value);
        else if (param == "ENEMY_SIZE_PLAYER_PLUS")
            ENEMY_SIZE_PLAYER_PLUS = stoi(value);
        else if (param == "ENEMY_SPEED_BASE")
            ENEMY_SPEED_BASE = stoi(value);
        else if (param == "ENEMY_SPEED_PLUS_RANDOM")
            ENEMY_SPEED_PLUS_RANDOM = stoi(value);
    }
}