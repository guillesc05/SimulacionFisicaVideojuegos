#pragma once
#include "DirectionalForceGenerator.h"
class WindForceGenerator: public DirectionalForceGenerator
{
public:
	WindForceGenerator(physx::PxVec3 direction, double magnitude, double k1, double k2);
	void applyForce(Particle* p) override;
private:
	double _k1, _k2;
};

