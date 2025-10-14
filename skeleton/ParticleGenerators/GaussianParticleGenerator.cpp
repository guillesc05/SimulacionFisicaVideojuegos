#include "GaussianParticleGenerator.h"

GaussianParticleGenerator::GaussianParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, double d, double v, double pv, double rv, double dv, double vv): ParticleGenerator(p, r, d, v),
	_positionVariation(pv), _directionVariation(rv), _durationVariation(dv), _velocityVariation(vv)
{

}

physx::PxVec3 GaussianParticleGenerator::getNewParticlePosition() {
	return _basePosition + _positionVariation* physx::PxVec3(_normalDistribution(_mt), _normalDistribution(_mt), _normalDistribution(_mt)).getNormalized();
}

physx::PxVec3 GaussianParticleGenerator::getNewParticleDirection() {
	return _baseDirection +_directionVariation * physx::PxVec3(_normalDistribution(_mt), _normalDistribution(_mt), _normalDistribution(_mt)).getNormalized();
}

double GaussianParticleGenerator::getNewParticleDuration() {
	return _baseDuration + _durationVariation * _normalDistribution(_mt);
}

double GaussianParticleGenerator::getNewParticleVelocityModule() {
	return _baseVelocity + _velocityVariation * _normalDistribution(_mt);
}
