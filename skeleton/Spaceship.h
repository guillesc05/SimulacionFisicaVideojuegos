#pragma once
#include "Entities/Particles.h"
class Spaceship: public Particle
{
public:
	Spaceship(physx::PxVec3 pos = physx::PxVec3(0), physx::PxVec3 vel = physx::PxVec3(0), float mass = 1, float damp = 1);
	void keyPressed(unsigned char c);
	void update(double t) override;

private:
	const double IMPULSE_FORCE = 1000.;
};

