#include "Bullet.h"
#include "OperationUtils.h"
#include "ParticleGenerators/GaussianParticleGenerator.h"

Bullet::Bullet(physx::PxVec3 pos, physx::PxVec3 velocity, ParticleSystem<CustomParticle>* bulletParticleSystem, physx::PxQuat rotation): PhysxParticle(pos, velocity,ROCKET_MASS,0, PhysxParticle::BULLET)  {
	changeRenderItem(CreateShape(physx::PxBoxGeometry(2.0f, .5f, 0.5f)));
	auto tr = _body->getGlobalPose();
	tr.q = rotation;
	_body->setGlobalPose(tr);
	_body->setLinearVelocity(velocity);

	_rocketParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0, 0, 1), 2, 10, 0, 0.05, .1, 15);
	_rocketParticles->setColor(physx::PxVec4(122. / 255., 131. / 255., 103. / 255., .5));
	bulletParticleSystem->addParticleGenerator(_rocketParticles);

	_body->setRigidDynamicLockFlags(physx::PxRigidDynamicLockFlag::eLOCK_LINEAR_Y | physx::PxRigidDynamicLockFlag::eLOCK_ANGULAR_X | physx::PxRigidDynamicLockFlag::eLOCK_ANGULAR_Z);
}

void Bullet::update(double t) {
	_rocketParticles->setBasePosition(getPosition());
	_rocketParticles->setBaseDirection(-getRotationDirection());

	currentTime += t;
	if (currentTime >= TIME_ALIVE) {
		_rocketParticles->setActive(false);
	}
}