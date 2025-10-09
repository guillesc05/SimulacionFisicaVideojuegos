#pragma once
#include <PxPhysicsAPI.h>
#include "../RenderUtils.hpp"
class Particle {
public:
	Particle(physx::PxVec3 pos = physx::PxVec3(0), physx::PxVec3 vel = physx::PxVec3(0),float mass = 1 ,physx::PxVec3 accel = physx::PxVec3(0), float damp = 1);
	~Particle();

	void integrate(double t);
private:
	physx::PxVec3 vel;
	physx::PxVec3 accel;

	float damping = 1;

	float mass = 1.f;

	RenderItem* renderItem;
	physx::PxTransform* transform;
};
