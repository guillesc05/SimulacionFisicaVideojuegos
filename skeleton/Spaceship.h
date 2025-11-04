#pragma once
#include "Entities/Particles.h"
#include "ParticleGenerators/GaussianParticleGenerator.h"
class Spaceship: public Particle
{
private:
	const double IMPULSE_FORCE = 1000.;
	GaussianParticleGenerator* _engineParticles;

	static constexpr double SHIP_DAMP = 0.5;
	static constexpr double SHIP_MASS = 1;
public:
	Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle);
	void keyPressed(unsigned char c);
	void update(double t) override;

};

