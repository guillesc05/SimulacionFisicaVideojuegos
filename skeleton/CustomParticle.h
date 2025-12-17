#pragma once
#include "Entities/Particles.h"

class CustomParticle: public Particle
{
public:

	CustomParticle(physx::PxVec3 pos = physx::PxVec3(0), physx::PxVec3 vel = physx::PxVec3(0), float mass = 1, float damp = 1);
	~CustomParticle();

	void integrate(double t) override;
	void addForce(physx::PxVec3 force) override;

	physx::PxVec3 getPosition() override;
	physx::PxVec3 getVelocity() override;

	virtual void update(double t)override{}

	float getDamping() override;
	void setDamping(float d) override;

	float getMass() override;

	physx::PxVec3 getRotation() override;
	void addRotation(physx::PxVec3 r) override;

	physx::PxVec3 getRotationDirection() override;


	void changeColor(physx::PxVec4 color) override;

	void changeRenderItem(physx::PxShape* shape) override;

protected:
	physx::PxVec3 vel;

	float damping = 1;

	float mass = 1.f;
	float inverseMass = 1.f;

	physx::PxTransform* transform;

	physx::PxVec3 forceVector;
};

