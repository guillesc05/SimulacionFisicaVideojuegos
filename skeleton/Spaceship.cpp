#include "Spaceship.h"
#include "RenderUtils.hpp"
#include "KeyboardState.h"

Spaceship::Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle): Particle(pos, physx::PxVec3(0), SHIP_MASS, SHIP_DAMP), _engineParticles(engineParticle) {
	DeregisterRenderItem(renderItem);
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(2.0f,2.0f, 2.0f));
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

void Spaceship::update(double t) {
	keyPressed(t);

	GetCamera()->setEye(transform->p + physx::PxVec3(0.01, 100, 0));
	GetCamera()->setDir((transform->p - GetCamera()->getEye()).getNormalized());

	_engineParticles->setBasePosition(transform->p);
	_engineParticles->setBaseDirection(transform->q.rotate(physx::PxVec3(-1,0,0)));
}

void Spaceship::keyPressed(double t) {

	if (KeyboardState::Instance()->getKeyState('u')) {
		addForce(getRotationDirection() * IMPULSE_FORCE_PER_SECOND*t);
	}

	if (KeyboardState::Instance()->getKeyState('j')) {
		addForce(getRotationDirection() * -IMPULSE_FORCE_PER_SECOND*t);
	}

	if (KeyboardState::Instance()->getKeyState('h')) {
		setRotation(getRotation() + physx::PxVec3(0, ROTATION_VELOCITY, 0)*t);
	}

	if (KeyboardState::Instance()->getKeyState('k')) {
		setRotation(getRotation() + physx::PxVec3(0, -ROTATION_VELOCITY, 0)*t);
	}
}