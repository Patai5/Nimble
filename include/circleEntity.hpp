#pragma once
#include <SFML/graphics.hpp>
#include "vect2.hpp"

class CircleEntity
{
public:
    CircleEntity(float radius, Vect2 position, sf::Color color);
    Vect2 get_position() const;
    void set_position(Vect2 position);

    bool outside_window(const int &width, const int &height) const;
    void draw(sf::RenderWindow &window) const;

protected:
    float radius;
    Vect2 position;
    sf::Color color;
};