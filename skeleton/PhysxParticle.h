#pragma once
#include "Entities/Particles.h"
#include <PxRigidBody.h>

class PhysxParticle: public Particle
{
public:

	enum PhysxParticleType {
		SPACESHIP, ENEMY_ALIVE, ENEMY_DEAD, BULLET, OTHER
	};

	PhysxParticle(physx::PxVec3 pos = physx::PxVec3(0), physx::PxVec3 vel = physx::PxVec3(0), float mass = 1, float damp = 1, PhysxParticleType type = OTHER);
	~PhysxParticle();

	void integrate(double t) override;
	void addForce(physx::PxVec3 force) override;

	physx::PxVec3 getPosition() override;
	physx::PxVec3 getVelocity() override;

	virtual void update(double t)override {}

	float getDamping() override;
	void setDamping(float d) override;

	float getMass() override;

	physx::PxVec3 getRotation() override;
	void addRotation(physx::PxVec3 r) override;

	physx::PxVec3 getRotationDirection() override;

	void changeColor(physx::PxVec4 color) override;

	void changeRenderItem(physx::PxShape* shape) override;

	virtual void onCollision(PhysxParticle* actorCollided) {};

	PhysxParticleType getType();

protected:
	physx::PxRigidDynamic* _body;
	PhysxParticleType _type;
};

