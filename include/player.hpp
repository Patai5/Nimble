#pragma once
#include "circleEntity.hpp"

class Player : public CircleEntity
{
public:
    Player(float radius, Vect2 position, sf::Color color);
};