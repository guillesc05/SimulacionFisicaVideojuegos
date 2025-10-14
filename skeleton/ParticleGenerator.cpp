#include "ParticleGenerator.h"
#include "Entities/Particles.h"

ParticleGenerator::ParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, double d, double v):_basePosition(p), _baseDirection(r), _baseDuration(d), _baseVelocity(v) {
	
}

ParticleWithDuration ParticleGenerator::generateNewParticle() {
	Particle* p = new Particle(getNewParticlePosition(), getNewParticleDirection().getNormalized() * getNewParticleVelocityModule(), 1.0, physx::PxVec3(0, -100, 0));
	return { p, getNewParticleDuration() };
}

double ParticleGenerator::getNewParticleDuration() {
	return _baseDuration;
}

physx::PxVec3 ParticleGenerator::getNewParticlePosition() {
	return _basePosition;
}

physx::PxVec3 ParticleGenerator::getNewParticleDirection() {
	return _baseDirection;
}

double ParticleGenerator::getNewParticleVelocityModule() {
	return _baseVelocity;
}


