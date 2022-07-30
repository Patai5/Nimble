#include "enemy.hpp"

Enemy::Enemy(float radius, float speed, Vect2 position, Vect2 vector, sf::Color color)
    : CircleEntity(radius, position, color), speed(speed), vector(vector) {}

void Enemy::step(const int &deltaTime)
{
    position += vector * speed * deltaTime;
}