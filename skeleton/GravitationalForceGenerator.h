#pragma once
#include "DirectionalForceGenerator.h"
class GravitationalForceGenerator: public DirectionalForceGenerator
{
public:
	GravitationalForceGenerator(physx::PxVec3 direction, double magnitude);
	void applyForce(Particle* p) override;
};

