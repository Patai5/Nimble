#include "vect2.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

Vect2 Vect2::operator*(const float &num) const
{
    return Vect2{x * num, y * num};
}

void Vect2::operator+=(Vect2 other)
{
    x += other.x;
    y += other.y;
}

Vect2 Vect2::random_vector(const float &min, const float &max)
{
    const float randomAngle = (rand() % (int)(max - min) + min) * M_PI / 180.0f;
    return Vect2{std::cos(randomAngle), std::sin(randomAngle)};
}