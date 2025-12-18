#include "Enemy.h"
#include "Scene.h"
#include <cmath>
#include "SpringForceGenerator.h"
#include "CustomParticle.h"
#include "Bullet.h"

#include "GameInfoSingleton.h"
#include "ExplosionForceGenerator.h"

Enemy::Enemy(physx::PxVec3 pos, ParticleSystem<CustomParticle>* enemyParticleSystem, Scene* scene, int i) : PhysxParticle(pos, physx::PxVec3(0), ENEMY_MASS, ENEMY_DAMPING, PhysxParticle::ENEMY_ALIVE), _enemyParticleSystem(enemyParticleSystem), index(i) {
	changeRenderItem(CreateShape(physx::PxSphereGeometry(4)));
	changeColor(physx::PxVec4(1,0,1,1));

	_body->setRigidDynamicLockFlags(physx::PxRigidDynamicLockFlag::eLOCK_LINEAR_Y | physx::PxRigidDynamicLockFlag::eLOCK_ANGULAR_X | physx::PxRigidDynamicLockFlag::eLOCK_ANGULAR_Z);

	_springFG = new SpringForceGenerator(30, PARTICLE_DISTANCE);
	enemyParticleSystem->addForceGenerator(_springFG);
	for (int i = 0; i < NUM_PARTICLE; i++) {
		float currentAngle = 360. / NUM_PARTICLE;
		currentAngle *= i;

		physx::PxVec3 position(sin(currentAngle * std::_Pi_val / 180.), 0, cos(currentAngle * std::_Pi_val / 180.)); position *= PARTICLE_DISTANCE;
		position += getPosition();

		auto particle = new CustomParticle(position, physx::PxVec3(0), 0.5, 0.9);
		particle->changeRenderItem(CreateShape(physx::PxBoxGeometry(1, 1, 1)));
		particle->changeColor(physx::PxVec4(0, 1, 0, .1));
		_enemyParticleSystem->addPermanentParticle(particle);
		_springFG->connectParticles(this, particle);
	}
}

void Enemy::integrate(double t) {
	GameInfoSingleton::Instance()->setEnemyPos(index, getPosition());

	if (isDead) return;
	auto dir = GameInfoSingleton::Instance()->getPlayerPos() - getPosition();
	addForce(dir.getNormalized() * ENEMY_FORCE_APPLY);
}

void Enemy::onCollision(PhysxParticle* particleCollided) {
	if (particleCollided->getType() == BULLET && !isDead) {
		killEnemy();
	}
}

void Enemy::killEnemy() {
	isDead = true;
	changeColor(physx::PxVec4(28 / 255., 4 / 255., 27 / 255., 1));

	auto fG = new ExplosionForceGenerator(getPosition(), 100, 1, 30000);
	_enemyParticleSystem->addForceGenerator(fG);

	_springFG->clearAllConnections();

	GameInfoSingleton::Instance()->enemyKilled(index);
	_type = ENEMY_DEAD;
}
