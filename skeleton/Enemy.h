#pragma once
#include "PhysxParticle.h"
#include "ParticleSystem.h"
#include "CustomParticle.h"

class Scene;
class Enemy: public PhysxParticle
{
public:
	Enemy(physx::PxVec3 pos, ParticleSystem<CustomParticle>* enemyParticleSystem, Scene* scene);
	void integrate(double t) override;
	void killEnemy();
private:
	ParticleSystem<CustomParticle>* _enemyParticleSystem;

	static constexpr float ENEMY_MASS = 100;
	static constexpr float ENEMY_DAMPING = 1;
	static constexpr float ENEMY_FORCE_APPLY = 10000;

	static constexpr int NUM_PARTICLE = 100;
	static constexpr float PARTICLE_DISTANCE= 10;

	bool isDead = false;
};