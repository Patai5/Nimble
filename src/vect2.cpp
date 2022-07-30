#include "vect2.hpp"

Vect2 &Vect2::operator*(const float &num)
{
    x *= num;
    y *= num;
    return *this;
}

Vect2 &Vect2::operator+=(Vect2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}