#pragma once
#include "PhysxParticle.h"
#include "ParticleSystem.h"
#include "CustomParticle.h"

class Scene;
class SpringForceGenerator;
class Enemy: public PhysxParticle
{
public:
	Enemy(physx::PxVec3 pos, ParticleSystem<CustomParticle>* enemyParticleSystem, Scene* scene, int index);
	void integrate(double t) override;
	void onCollision(PhysxParticle* particleCollided) override;
	void killEnemy();
private:
	ParticleSystem<CustomParticle>* _enemyParticleSystem;
	float currentExplosionTime = 0;
	SpringForceGenerator* _springFG;

	static constexpr float ENEMY_MASS = 100;
	static constexpr float ENEMY_DAMPING = 1;
	static constexpr float ENEMY_FORCE_APPLY = 10000;

	static constexpr int NUM_PARTICLE = 30;
	static constexpr float PARTICLE_DISTANCE= 10;

	static constexpr float EXPLOSION_TIME = 1;

	bool isDead = false;

	int index = 0;
};