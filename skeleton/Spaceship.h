#pragma once
#include "Entities/Particles.h"
#include "ParticleGenerators/GaussianParticleGenerator.h"
#include "CustomParticle.h"
class Scene;
class Spaceship: public CustomParticle
{
private:
	Scene* _scene;
	const double IMPULSE_FORCE_PER_SECOND = 10000.;
	const double ROTATION_VELOCITY = 180.;

	const double SHOOT_VELOCITY = 100;

	bool cameraOnTop = true;

	GaussianParticleGenerator* _engineParticles;

	static constexpr double SHIP_DAMP = 0.5;
	static constexpr double SHIP_MASS = 1;

	bool pressingY = false;
	bool pressingShoot = false;
	void updateCamera();
	void shoot();
public:
	Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle, Scene* scene);
	void keyPressed(double t);
	void update(double t) override;

};

