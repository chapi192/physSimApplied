#include "Kinematics.h"

vecSpace::Vector2d Kinematics::kinematicsCalculator(Vector2d positionStart, Vector2d  velocityStart, Vector2d  accelerationStart, float simTime)
{
	Vector2d finalPosition;
	Vector2d calcFinalVelocity;

	calcFinalVelocity = velocityStart + accelerationStart * simTime;

	finalPosition = positionStart + ((velocityStart + calcFinalVelocity)*(0.5)) * simTime;

	return finalPosition;
}
