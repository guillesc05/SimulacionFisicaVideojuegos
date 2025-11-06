#pragma once
#include "Entities/Particles.h"
#include "ParticleGenerators/GaussianParticleGenerator.h"
class Spaceship: public Particle
{
private:
	const double IMPULSE_FORCE_PER_SECOND = 10000.;
	const double ROTATION_VELOCITY = 180.;

	bool cameraOnTop = true;

	GaussianParticleGenerator* _engineParticles;

	static constexpr double SHIP_DAMP = 0.5;
	static constexpr double SHIP_MASS = 1;

	bool pressingY = false;
public:
	Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle);
	void keyPressed(double t);
	void update(double t) override;

	void updateCamera();
};

