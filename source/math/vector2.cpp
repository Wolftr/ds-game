#include <math.h>
#include "vector2.h"

Vector2::Vector2() 
{
    x = 0;
    y = 0;
}

Vector2::Vector2(const float& x, const float& y)
{
    this->x = x;
    this->y = y;
}

bool Vector2::operator==(const Vector2& other) 
{
    return (x == other.x && y == other.y);
}

bool Vector2::operator!=(const Vector2& other) 
{
    return (x != other.x || y != other.y);
}

Vector2 Vector2::operator+(const Vector2& addend)
{
    return Vector2(x + addend.x, y + addend.y);
}

Vector2 Vector2::operator-(const Vector2& subtrahend)
{
    return Vector2(x - subtrahend.x, y - subtrahend.y);
}

Vector2 Vector2::operator*(const float& multiplier)
{
    return Vector2(x * multiplier, y * multiplier);
}

Vector2 Vector2::operator/(const float& divisor)
{
	return Vector2(x / divisor, y / divisor);
}

float Vector2::magnitude()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2 Vector2::normalized() 
{
    float m = magnitude();
	if (m == 0) return Vector2();
	return Vector2(x / m, y / m);
}

Vector2 Vector2::clampMagnitude(const float& maxMagnitude)
{
    float m = magnitude();
	float multiplier = 1;
	if (m > maxMagnitude) multiplier = maxMagnitude / m;
	return Vector2(x * multiplier, y * multiplier);
}