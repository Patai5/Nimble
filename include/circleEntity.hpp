#pragma once
#include <SFML/graphics.hpp>
#include "vect2.hpp"

class CircleEntity
{
public:
    CircleEntity(float radius, Vect2 position, sf::Color color);

    void set_position(Vect2 position);
    Vect2 get_position() const;
    void set_radius(const float &points);
    float get_radius() const;

    bool outside_window(const int &width, const int &height) const;
    void draw(sf::RenderWindow &window);
    bool sweep_prune_x(const float &otherLeft, const float &otherRight) const;
    bool is_colliding(const CircleEntity &other) const;

protected:
    float radius;
    Vect2 position;
    sf::CircleShape shape;
};