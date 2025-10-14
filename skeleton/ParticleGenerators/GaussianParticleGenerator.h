#pragma once
#include "../ParticleGenerator.h"
#include <random>

class GaussianParticleGenerator :public ParticleGenerator {
public:
	GaussianParticleGenerator();

	virtual physx::PxVec3 getNewParticlePosition() override;
	virtual physx::PxVec3 getNewParticleRotation() override;
	virtual double getNewParticleDuration() override;
	virtual double getNewParticleVelocityModule() override;

private:
	std::normal_distribution<double> _normalDistribution{ -1,1 };
	std::mt19937 _mt;
};