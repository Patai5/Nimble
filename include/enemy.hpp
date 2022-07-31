#pragma once
#include "circleEntity.hpp"

class Enemy : public CircleEntity
{
public:
    Enemy(float radius, float speed, Vect2 position, Vect2 vector, sf::Color color);

    static Enemy gen_rand_enemy(const int &width, const int &height, float minRadius, float maxRadius);
    void step(const float &deltaTime);

protected:
    float speed;
    Vect2 vector;
};
