#include "Vector3d.h"
#include <iostream>
#include <math.h>

using namespace vecSpace;

Vector3d::Vector3d() : x(x), y(y), z(z)
{
	x = 0;
	y = 0;
	z = 0;
}

void Vector3d::setXYZ(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void Vector3d::print(void)
{
	std::cout << "(" << x << " " << y << " " << z << ")";
}

double Vector3d::magnitude(void)
{
	return (pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5));
}

const Vector3d vecSpace::operator+(const Vector3d& vector3dLeft, const Vector3d& vector3dRight)
{
	Vector3d vec;
	vec.x = vector3dLeft.x + vector3dRight.x;
	vec.y = vector3dLeft.y + vector3dRight.y;
	vec.z = vector3dLeft.z + vector3dRight.z;
	return vec;
}

const Vector3d vecSpace::operator*(const Vector3d& vector3dLeft, const Vector3d& vector3dRight)
{
	Vector3d vec;
	vec.x = vector3dLeft.x * vector3dRight.x;
	vec.y = vector3dLeft.y * vector3dRight.y;
	vec.z = vector3dLeft.z * vector3dRight.z;
	return vec;
}

const Vector3d vecSpace::operator*(const Vector3d& vector3dLeft, long double num)
{
	Vector3d vec;
	vec.x = vector3dLeft.x * num;
	vec.y = vector3dLeft.y * num;
	vec.z = vector3dLeft.z * num;
	return vec;
}
