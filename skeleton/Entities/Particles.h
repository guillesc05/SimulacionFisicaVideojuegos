#pragma once
#include <PxPhysicsAPI.h>
#include "../RenderUtils.hpp"
class Particle {
public:
	Particle(physx::PxVec3 pos = physx::PxVec3(0), physx::PxVec3 vel = physx::PxVec3(0),float mass = 1 ,physx::PxVec3 accel = physx::PxVec3(0), float damp = 1);
	~Particle();

	void changeColor(physx::PxVec4 color);

	void integrate(double t);

	physx::PxVec3 getPosition();
private:
	physx::PxVec3 vel;
	physx::PxVec3 accel;

	float damping = 1;

	float mass = 1.f;

	RenderItem* renderItem;
	physx::PxTransform* transform;
};
