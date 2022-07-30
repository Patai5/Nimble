#pragma once
#include "circleEntity.hpp"

class Enemy : public CircleEntity
{
public:
    Enemy(float radius, float speed, Vect2 position, Vect2 vector, sf::Color color);
    void step(const int &deltaTime);

protected:
    float speed;
    Vect2 vector;
};
