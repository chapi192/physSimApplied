#include "Kinematics.h"

//where the object 'should' be
vecSpace::Vector2d Kinematics::kinematicsCalculator(Vector2d positionStart, Vector2d  velocityStart, Vector2d  accelerationStart, float simTime)
{
	Vector2d finalPosition;
	Vector2d calcFinalVelocity;

	//Vfinal = Vstart + a*t
	calcFinalVelocity = velocityStart + accelerationStart * simTime;

	//Xfinal = Xstart + ((Vstart + Vfinal)/2) * t
	finalPosition = positionStart + ((velocityStart + calcFinalVelocity)*(0.5)) * simTime;

	return finalPosition;
}
