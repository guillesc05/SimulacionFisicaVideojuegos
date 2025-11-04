#include "Spaceship.h"
#include "RenderUtils.hpp"

Spaceship::Spaceship(physx::PxVec3 pos, physx::PxVec3 vel, float mass, float damp): Particle(pos, vel, mass, damp) {
	DeregisterRenderItem(renderItem);
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(2.0f,2.0f, 2.0f));
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

void Spaceship::update(double t) {
	GetCamera()->setEye(transform->p + physx::PxVec3(0.01, 100, 0));
	GetCamera()->setDir((transform->p - GetCamera()->getEye()).getNormalized());
}

void Spaceship::keyPressed(unsigned char c) {
	auto rot = getRotation();
	switch (c) {
	case 'u':
		addForce(getRotationDirection()*IMPULSE_FORCE);
		break;
	case 'h':
		setRotation(rot + physx::PxVec3(0, 30, 0));
		break;
	case 'j':
		addForce(getRotationDirection() * -IMPULSE_FORCE);
		break;
	case 'k':
		setRotation(rot + physx::PxVec3(0, -30, 0));
		break;
	}
}