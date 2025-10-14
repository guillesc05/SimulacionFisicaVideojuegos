#include "GaussianParticleGenerator.h"

GaussianParticleGenerator::GaussianParticleGenerator(): ParticleGenerator(physx::PxVec3(0), physx::PxVec3(0, 0, 1), .5, 200) {

}

physx::PxVec3 GaussianParticleGenerator::getNewParticlePosition() {
	return _basePosition + 10* physx::PxVec3(_normalDistribution(_mt), _normalDistribution(_mt), _normalDistribution(_mt));
}

physx::PxVec3 GaussianParticleGenerator::getNewParticleRotation() {
	return ParticleGenerator::getNewParticleRotation();
}

double GaussianParticleGenerator::getNewParticleDuration() {
	return ParticleGenerator::getNewParticleDuration();
}

double GaussianParticleGenerator::getNewParticleVelocityModule() {
	return ParticleGenerator::getNewParticleVelocityModule();
}
