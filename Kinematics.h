#pragma once
#include "Vector2d.h"

class Kinematics : public vecSpace::Vector2d
{
public:
	Vector2d kinematicsCalculator(Vector2d positionStart, Vector2d  velocityStart, Vector2d  accelerationStart, float simTime);
};

