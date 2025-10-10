#pragma once
#include <PxPhysicsAPI.h>
class Particle;
class ParticleGenerator
{
public:
	ParticleGenerator(physx::PxVec3 position, physx::PxVec3 rotation, float duration);

	Particle* generateNewParticle();

protected:
	physx::PxVec3 _basePosition;
	physx::PxVec3 _baseRotation;
	float _baseDuration;

	virtual physx::PxVec3 getNewParticlePosition();
	virtual physx::PxVec3 getNewParticleRotation();
	virtual float getNewParticleDuration();
};

