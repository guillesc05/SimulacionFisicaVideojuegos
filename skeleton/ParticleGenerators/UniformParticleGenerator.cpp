#include "UniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, double d, double v, double pv, double rv, double dv, double vv) : ParticleGenerator(p, r, d, v),
_positionVariation(pv), _directionVariation(rv), _durationVariation(dv), _velocityVariation(vv)
{

}

physx::PxVec3 UniformParticleGenerator::getNewParticlePosition() {
	return _basePosition + _positionVariation * physx::PxVec3(_uniformDistribution(_mt), _uniformDistribution(_mt), _uniformDistribution(_mt));
}

physx::PxVec3 UniformParticleGenerator::getNewParticleDirection() {
	return _baseDirection + _directionVariation * physx::PxVec3(_uniformDistribution(_mt), _uniformDistribution(_mt), _uniformDistribution(_mt)).getNormalized();
}

double UniformParticleGenerator::getNewParticleDuration() {
	return _baseDuration + _durationVariation * _uniformDistribution(_mt);
}

double UniformParticleGenerator::getNewParticleVelocityModule() {
	return _baseVelocity + _velocityVariation * _uniformDistribution(_mt);
}
