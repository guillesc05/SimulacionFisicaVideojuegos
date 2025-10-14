#pragma once
#include "../ParticleGenerator.h"
#include <random>

class UniformParticleGenerator :public ParticleGenerator {
public:
	UniformParticleGenerator(physx::PxVec3 position, physx::PxVec3 rotation, double duration, double velocityModule, double positionVariation,
		double rotationVariation, double durationVariation, double velocityVariation);

	virtual physx::PxVec3 getNewParticlePosition() override;
	virtual physx::PxVec3 getNewParticleDirection() override;
	virtual double getNewParticleDuration() override;
	virtual double getNewParticleVelocityModule() override;

private:
	std::uniform_real<double> _uniformDistribution{ -1,1 };
	std::mt19937 _mt;

	double _positionVariation;
	double _directionVariation;
	double _durationVariation;
	double _velocityVariation;
};