#pragma once
#include "ForceGenerator.h"
#include <PxPhysicsAPI.h>
class DirectionalForceGenerator: public ForceGenerator
{
public:
	DirectionalForceGenerator(physx::PxVec3 direction, double magnitude);
	virtual void applyForce(Particle* p) override;
protected:
	physx::PxVec3 _direction;
};

