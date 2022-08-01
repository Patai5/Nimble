#include <cmath>
#include "circleEntity.hpp"

void CircleEntity::set_position(Vect2 position)
{
    this->position = position;
}

Vect2 CircleEntity::get_position() const
{
    return position;
}

void CircleEntity::set_radius(const float &radius)
{
    this->radius = radius;
    shape = sf::CircleShape(radius);
}

float CircleEntity::get_radius() const
{
    return radius;
}

CircleEntity::CircleEntity(float radius, Vect2 position, sf::Color color)
    : radius(radius), position(position), shape(sf::CircleShape(radius))
{
    shape.setFillColor(color);
}

bool CircleEntity::outside_window(const int &width, const int &height) const
{
    if (position.x + radius < 0)
        return true;
    if (position.x - radius > width)
        return true;
    if (position.y + radius < 0)
        return true;
    if (position.y - radius > height)
        return true;
    return false;
}

void CircleEntity::draw(sf::RenderWindow &window)
{
    shape.setPosition(position.x - radius, position.y - radius);
    window.draw(shape);
}

bool CircleEntity::sweep_prune_x(const float &otherLeft, const float &otherRight) const
{
    if (position.x + radius < otherLeft)
        return false;
    if (position.x - radius > otherRight)
        return false;
    return true;
}

bool CircleEntity::is_colliding(const CircleEntity &other) const
{
    return pow(position.x - other.position.x, 2) + pow(position.y - other.position.y, 2) < pow(radius + other.radius, 2);
}