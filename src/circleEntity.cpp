#include "circleEntity.hpp"

void CircleEntity::set_position(Vect2 position)
{
    this->position = position;
}

Vect2 CircleEntity::get_position() const
{
    return position;
}

CircleEntity::CircleEntity(float radius, Vect2 position, sf::Color color)
    : radius(radius), position(position), color(color) {}

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

void CircleEntity::draw(sf::RenderWindow &window) const
{
    sf::CircleShape circle(radius);
    circle.setPosition(position.x, position.y);
    circle.setFillColor(color);
    window.draw(circle);
}