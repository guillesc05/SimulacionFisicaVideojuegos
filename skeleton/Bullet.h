#pragma once
#include "PhysxParticle.h"
#include "ParticleSystem.h"
#include "CustomParticle.h"

class GaussianParticleGenerator;
class Bullet: public PhysxParticle
{
	GaussianParticleGenerator* _rocketParticles;
	constexpr static float TIME_ALIVE = 2;
	constexpr static float ROCKET_MASS = 10;
	float currentTime = 0;
public:
	Bullet(physx::PxVec3 pos, physx::PxVec3 direction, ParticleSystem<CustomParticle>* bulletParticleSystem, physx::PxQuat rotation);
	void update(double t) override;
};

