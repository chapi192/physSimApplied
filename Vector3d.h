#pragma once
//a custom namespace is required to overload a function
namespace vecSpace
{
	class Vector3d
	{
		//public means that once we make an instance of the class, these functions/variables are avaliable
	public:
		double x;
		double y;
		double z;

		Vector3d();

		void setXYZ(double a, double b, double c);
		void print(void);
		double magnitude(void);
	};
	//overloaded functions. Lets us define what it means to add, multiply, or whatever two vectors. 
	const Vector3d operator+(const Vector3d& vector3dLeft, const Vector3d& vector3dRight);

	const Vector3d operator*(const Vector3d& vector3dLeft, const Vector3d& vector3dRight);

	//overloaded fucntion of a vector and some other number.
	const Vector3d operator*(const Vector3d& vector3dLeft, long double num);

}

