#include "player.hpp"

Player::Player(float radius, Vect2 position, sf::Color color)
    : CircleEntity(radius, position, color) {}

void Player::set_mouse_position(const int &width, const int &height, sf::RenderWindow &window)
{
    Vect2 mousePosition{(float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y};

    if (mousePosition.x < 0)
        mousePosition.x = 0;
    if (mousePosition.x > width)
        mousePosition.x = width;
    if (mousePosition.y < 0)
        mousePosition.y = 0;
    if (mousePosition.y > height)
        mousePosition.y = height;

    position = mousePosition;
}