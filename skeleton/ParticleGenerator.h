#pragma once
#include <PxPhysicsAPI.h>
#include <random>
class Particle;

struct ParticleWithDuration {
	Particle* particle;
	double deadTime;

	bool operator==(const ParticleWithDuration& r)const& {
		return particle == r.particle;
	}
};

class ParticleGenerator
{
public:
	ParticleGenerator(physx::PxVec3 position, physx::PxVec3 rotation, double duration, double velocityModule);

	ParticleWithDuration generateNewParticle();

protected:
	physx::PxVec3 _basePosition;
	physx::PxVec3 _baseRotation;
	double _baseDuration;
	double _baseVelocity;

	virtual physx::PxVec3 getNewParticlePosition();
	virtual physx::PxVec3 getNewParticleRotation();
	virtual double getNewParticleDuration();
	virtual double getNewParticleVelocityModule();
};

