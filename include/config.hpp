#pragma once

#include <string>

extern std::string FONTS_PATH;
extern float FPS;
extern int WIDTH, HEIGHT;
extern int unsigned ENEMY_COUNT;
extern int ENEMY_SIZE_PLAYER_MINUS, ENEMY_SIZE_PLAYER_PLUS;
extern int ENEMY_SPEED_BASE, ENEMY_SPEED_PLUS_RANDOM;

void loadConfig();