#pragma once
#include "WindForceGenerator.h"
class WhirlwindForceGenerator: public WindForceGenerator
{
public:
	WhirlwindForceGenerator(double magnitude, double k1, double k2, physx::PxVec3 position);
private:
	physx::PxVec3 getWindVelocity(Particle* p) override;
};

