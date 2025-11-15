#pragma once
#include "SpringForceGenerator.h"
#include <PxPhysicsAPI.h>
class AnchoredSpringForceGenerator: public SpringForceGenerator
{
public:
	AnchoredSpringForceGenerator(double k, double resting, physx::PxVec3 v);

	~AnchoredSpringForceGenerator();
};

