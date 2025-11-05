#include "ParticleGenerator.h"
#include "Entities/Particles.h"

ParticleGenerator::ParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, double d, double v):_basePosition(p), _baseDirection(r), _baseDuration(d), _baseVelocity(v) {
	
}

ParticleWithAttributes ParticleGenerator::generateNewParticle() {
	auto pos = getNewParticlePosition();
	Particle* p = new Particle(pos, getNewParticleDirection().getNormalized() * getNewParticleVelocityModule(), 1.0, 0.9f);
	p->changeColor(_color);
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

physx::PxVec3 ParticleGenerator::getBasePosition() {
	return _basePosition;
}

physx::PxVec3 ParticleGenerator::getBaseDirection() {
	return _baseDirection;
}

double ParticleGenerator::getBaseDuration() {
	return _baseDuration;
}

double ParticleGenerator::getBaseVelocity() {
	return _baseVelocity;
}

void ParticleGenerator::setBasePosition(physx::PxVec3 v) {
	_basePosition = v;
}

void ParticleGenerator::setBaseDirection(physx::PxVec3 v) {
	_baseDirection = v;
}

void ParticleGenerator::setBaseDuration(double d) {
	_baseDuration = d;
}
void ParticleGenerator::setBaseVelocity(double d) {
	_baseVelocity = d;
}

void ParticleGenerator::setActive(bool b) {
	canGenerate = b;
}

bool ParticleGenerator::isActive() {
	return canGenerate;
}

void ParticleGenerator::setColor(physx::PxVec4 col) {
	_color = col;
}


