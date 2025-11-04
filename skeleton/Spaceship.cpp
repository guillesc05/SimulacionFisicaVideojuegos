#include "Spaceship.h"
#include "RenderUtils.hpp"

Spaceship::Spaceship(physx::PxVec3 pos, physx::PxVec3 vel, float mass, float damp): Particle(pos, vel, mass, damp) {
	DeregisterRenderItem(renderItem);
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(2.0f,2.0f, 2.0f));
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

void Spaceship::update(double t) {
	auto rot = getRotation();
	setRotation(rot + physx::PxVec3(0, 360, 0)*t);
}

void Spaceship::keyPressed(unsigned char c) {
	switch (c) {
	case 'u':
		addForce(physx::PxVec3(IMPULSE_FORCE, 0, 0));
		break;
	case 'h':
		addForce(physx::PxVec3(0, 0, -IMPULSE_FORCE));
		break;
	case 'j':
		addForce(physx::PxVec3(-IMPULSE_FORCE, 0, 0));
		break;
	case 'k':
		addForce(physx::PxVec3(0, 0, IMPULSE_FORCE));
		break;
	}
}