#include "ParticleGenerator.h"
#include "Entities/Particles.h"

ParticleGenerator::ParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, double d, double v):_basePosition(p), _baseDirection(r), _baseDuration(d), _baseVelocity(v) {
	
}

ParticleWithAttributes ParticleGenerator::generateNewParticle() {
	auto pos = getNewParticlePosition();
	Particle* p = new Particle(pos, getNewParticleDirection().getNormalized() * getNewParticleVelocityModule(), 1.0, 0.9f);
	p->changeColor(physx::PxVec4(0, 0, 1, 1));
	return { p, getNewParticleDuration(), pos };
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


