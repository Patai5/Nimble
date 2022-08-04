#include "enemy.hpp"
#include "config.hpp"

Enemy::Enemy(float radius, float speed, Vect2 position, Vect2 vector, sf::Color color)
    : CircleEntity(radius, position, color), speed(speed), vector(vector) {}

void Enemy::step(const float &deltaTime)
{
    position += vector * speed * deltaTime;
}

Enemy Enemy::gen_rand_enemy(const int &width, const int &height, float minRadius, float maxRadius)
{
    if (minRadius < 0.0f)
        minRadius = 0.0f;

    const int radius = (rand() % (int)(maxRadius - minRadius)) + minRadius;

    const int speed = (rand() % ENEMY_SPEED_PLUS_RANDOM) + ENEMY_SPEED_BASE;

    const int circumference = width + height + radius * 4 - 4;
    const int halfway = width + radius * 2 - 2;
    const int randCircumference = rand() % circumference;
    Vect2 vector;
    Vect2 position = Vect2{0.0f, 0.0f};
    if (randCircumference < halfway)
    {
        if (randCircumference % 2)
        {
            position.y = -radius;
            vector = Vect2::random_vector(0.0f, 180.0f);
        }
        else
        {
            position.y = height + radius;
            vector = Vect2::random_vector(180.0f, 360.0f);
        }
        position.x = randCircumference - radius + 1;
    }
    else
    {
        if (randCircumference % 2)
        {
            position.x = -radius;
            if (rand() % 2 == 0)
                vector = Vect2::random_vector(0.0f, 90.0f);
            else
                vector = Vect2::random_vector(270.0f, 360.0f);
        }
        else
        {
            position.x = width + radius;
            vector = Vect2::random_vector(90.0f, 270.0f);
        }
        position.y = randCircumference - halfway - radius + 1;
    }

    sf::Color color((rand() % 215) + 40, (rand() % 215) + 40, (rand() % 215) + 40);

    return Enemy(radius, speed, position, vector, color);
}