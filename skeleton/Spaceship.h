#pragma once
#include "Entities/Particles.h"
#include "ParticleGenerators/GaussianParticleGenerator.h"
#include "PhysxParticle.h"
#include "ParticleSystem.h"
#include "CustomParticle.h"

#include <vector>
class Scene;
class Spaceship: public PhysxParticle
{
private:
	Scene* _scene;
	ParticleSystem<CustomParticle>* _bulletPSystem;
	const double IMPULSE_FORCE_PER_SECOND = 10000000.;
	const double ROTATION_VELOCITY = 180.;

	const double SHOOT_VELOCITY = 200;

	bool cameraOnTop = true;

	GaussianParticleGenerator* _engineParticles;

	static constexpr double SHIP_DAMP = 0.5;
	static constexpr double SHIP_MASS = 1000;

	static constexpr double CANNON_DAMP = 0.1;
	static constexpr double CANNON_MASS = 30;
	static constexpr double BACKLASH_MAGNITUDE = 50000;

	static constexpr double MAX_CANNON_DISTANCE = 7;

	CustomParticle* _cannonParticle;

	bool pressingY = false;
	bool pressingShoot = false;
	void updateCamera();
	void shoot();

	std::vector<CustomParticle*> _enemyIndicators;
public:
	Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle, ParticleSystem<CustomParticle>* bulletParticleSystem ,Scene* scene, int numberOfEnemies);
	void keyPressed(double t);
	void update(double t) override;

};

