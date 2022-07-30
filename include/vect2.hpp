#pragma once

struct Vect2
{
    float x;
    float y;

    Vect2 &operator*(const float &num);
    Vect2 &operator+=(Vect2 &other);
};