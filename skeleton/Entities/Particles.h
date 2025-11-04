#pragma once
#include <PxPhysicsAPI.h>
#include "../RenderUtils.hpp"
#include "../UpdateableObject.h"
class Particle: public UpdateableObject {
public:
	Particle(physx::PxVec3 pos = physx::PxVec3(0), physx::PxVec3 vel = physx::PxVec3(0),float mass = 1 , float damp = 1);
	~Particle();

	void changeColor(physx::PxVec4 color);

	void integrate(double t) override;
	virtual void update(double t){}
	void addForce(physx::PxVec3 force);

	physx::PxVec3 getPosition();
	physx::PxVec3 getVelocity();

	float getDamping();
	void setDamping(float d);

	float getMass();

	physx::PxVec3 getRotation();
	void setRotation(physx::PxVec3 r);

	physx::PxVec3 getRotationDirection();

protected:
	physx::PxVec3 vel;

	float damping = 1;

	float mass = 1.f;
	float inverseMass = 1.f;

	RenderItem* renderItem;
	physx::PxTransform* transform;

	physx::PxVec3 forceVector;
};
