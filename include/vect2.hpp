#pragma once

struct Vect2
{
    float x;
    float y;

    Vect2 operator*(const float &num) const;
    void operator+=(Vect2 other);

    static Vect2 random_vector(const float &min, const float &max);
};