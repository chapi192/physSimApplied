#pragma once

namespace vecSpace
{
	class Vector3d
	{
	public:
		double x;
		double y;
		double z;

		Vector3d();

		//accesor

		void setXYZ(double a, double b, double c);
		void print(void);
		double magnitude(void);
	};

	const Vector3d operator+(const Vector3d& vector3dLeft, const Vector3d& vector3dRight);

	const Vector3d operator*(const Vector3d& vector3dLeft, const Vector3d& vector3dRight);
	const Vector3d operator*(const Vector3d& vector3dLeft, long double num);

}

