#include "ParticleGenerator.h"
#include "Entities/Particles.h"

ParticleGenerator::ParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, double d, double v):_basePosition(p), _baseRotation(r), _baseDuration(d), _baseVelocity(v) {
	
}

ParticleWithDuration ParticleGenerator::generateNewParticle() {
	Particle* p = new Particle(getNewParticlePosition(), getNewParticleRotation().getNormalized() * getNewParticleVelocityModule());
	return { p, getNewParticleDuration() };
}

double ParticleGenerator::getNewParticleDuration() {
	return _baseDuration;
}

physx::PxVec3 ParticleGenerator::getNewParticlePosition() {
	return _basePosition;
}

physx::PxVec3 ParticleGenerator::getNewParticleRotation() {
	return _baseRotation;
}

double ParticleGenerator::getNewParticleVelocityModule() {
	return _baseVelocity;
}


