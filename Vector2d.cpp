#include "Vector2d.h"
#include <iostream>
#include <math.h>

using namespace vecSpace;

Vector2d::Vector2d() : x(x), y(y)
{
	x = 0;
	y = 0;
}

void Vector2d::setXYZ(double a, double b)
{
	x = a;
	y = b;
}

void Vector2d::print(void)
{
	std::cout << "(" << x << " " << y << ")";
}

double Vector2d::magnitude(void)
{
	return (pow(pow(x, 2) + pow(y, 2), 0.5));
}

const Vector2d vecSpace::operator+(const Vector2d& Vector2dLeft, const Vector2d& Vector2dRight)
{
	Vector2d vec;
	vec.x = Vector2dLeft.x + Vector2dRight.x;
	vec.y = Vector2dLeft.y + Vector2dRight.y;
	return vec;
}

const Vector2d vecSpace::operator*(const Vector2d& Vector2dLeft, const Vector2d& Vector2dRight)
{
	Vector2d vec;
	vec.x = Vector2dLeft.x * Vector2dRight.x;
	vec.y = Vector2dLeft.y * Vector2dRight.y;
	return vec;
}

const Vector2d vecSpace::operator*(const Vector2d& Vector2dLeft, long double num)
{
	Vector2d vec;
	vec.x = Vector2dLeft.x * num;
	vec.y = Vector2dLeft.y * num;
	return vec;
}
