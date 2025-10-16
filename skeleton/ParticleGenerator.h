#pragma once
#include <PxPhysicsAPI.h>
#include <random>
class Particle;

struct ParticleWithAttributes {
	Particle* particle;
	double deadTime;
	physx::PxVec3 initialPosition;
	bool operator==(const ParticleWithAttributes& r)const& {
		return particle == r.particle;
	}
};

class ParticleGenerator
{
public:
	ParticleGenerator(physx::PxVec3 position, physx::PxVec3 rotation, double duration, double velocityModule);

	ParticleWithAttributes generateNewParticle();

protected:
	physx::PxVec3 _basePosition;
	physx::PxVec3 _baseDirection;
	double _baseDuration;
	double _baseVelocity;

	virtual physx::PxVec3 getNewParticlePosition();
	virtual physx::PxVec3 getNewParticleDirection();
	virtual double getNewParticleDuration();
	virtual double getNewParticleVelocityModule();
};

