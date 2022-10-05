//see vector3d for comments

#pragma once

namespace vecSpace
{
	class Vector2d
	{
	public:
		double x;
		double y;

		Vector2d();

		//accesor

		void setXYZ(double a, double b);
		void print(void);
		double magnitude(void);
	};

	const Vector2d operator+(const Vector2d& vector3dLeft, const Vector2d& vector3dRight);

	const Vector2d operator*(const Vector2d& vector3dLeft, const Vector2d& vector3dRight);
	const Vector2d operator*(const Vector2d& vector3dLeft, long double num);

}


