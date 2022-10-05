#pragma once
#include "Vector2d.h"

//the Kinematics class inherits from Vector2d. This means that everything Vector2d has, so too does Kinematics. 
class Kinematics : public vecSpace::Vector2d
{
public:
	//constructor for the kinematicsCalculator function in .cpp
	Vector2d kinematicsCalculator(Vector2d positionStart, Vector2d  velocityStart, Vector2d  accelerationStart, float simTime);
};

