#pragma once
#include "ForceGenerator.h"
#include <PxPhysicsAPI.h>
class ExplosionForceGenerator : public ForceGenerator
{
public:
	ExplosionForceGenerator(physx::PxVec3 pos, double r, double tC, double explosionForce);
	void applyForce(Particle* p) override;
private:
	physx::PxVec3 _position;
	double _radius;
	double _timeConstant;
};

