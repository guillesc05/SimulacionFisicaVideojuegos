#include "Spaceship.h"
#include "RenderUtils.hpp"
#include "KeyboardState.h"
#include "Scene.h"

Spaceship::Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle, Scene* s): CustomParticle(pos, physx::PxVec3(0), SHIP_MASS, SHIP_DAMP), _engineParticles(engineParticle),
_scene(s)
{
	DeregisterRenderItem(renderItem);
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(2.0f,2.0f, 2.0f));
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

void Spaceship::update(double t) {
	updateCamera();
	keyPressed(t);


	_engineParticles->setBasePosition(transform->p);
	_engineParticles->setBaseDirection(transform->q.rotate(physx::PxVec3(-1,0,0)));
}

void Spaceship::updateCamera() {
	physx::PxVec3 camPos;
	physx::PxVec3 camDir;

	if (cameraOnTop) {
		camPos = transform->p + physx::PxVec3(20, 100, 0);
		camDir = (transform->p - GetCamera()->getEye()).getNormalized();
	}
	else {
		camPos = transform->p + physx::PxVec3(0.01, 2.5, 0);
		camDir = getRotationDirection();
	}

	GetCamera()->setDir(camDir);
	GetCamera()->setEye(camPos);
	
}

void Spaceship::shoot() {
	physx::PxVec3 dir;
	if (cameraOnTop) dir = getRotationDirection();
	else dir = GetCamera()->getDir();

	Particle* p = new CustomParticle(transform->p, vel+dir * SHOOT_VELOCITY, 1, 1);
	_scene->pushUpdateableObject(p);
}

void Spaceship::keyPressed(double t) {

	if (KeyboardState::Instance()->getKeyState('u')) {
		addForce(getRotationDirection() * IMPULSE_FORCE_PER_SECOND * t);
		_engineParticles->setActive(true);
	}
	else _engineParticles->setActive(false);

	if (KeyboardState::Instance()->getKeyState('j')) {
		addForce(getRotationDirection() * -IMPULSE_FORCE_PER_SECOND*t);
	}

	if (KeyboardState::Instance()->getKeyState('h')) {
		setRotation(getRotation() + physx::PxVec3(0, ROTATION_VELOCITY, 0)*t);
	}

	if (KeyboardState::Instance()->getKeyState('k')) {
		setRotation(getRotation() + physx::PxVec3(0, -ROTATION_VELOCITY, 0)*t);
	}

	if (!KeyboardState::Instance()->getKeyState('y')) {
		pressingY = false;
	}
	if(KeyboardState::Instance()->getKeyState('y') && !pressingY) {
		pressingY = true;
		cameraOnTop = !cameraOnTop;
	}
	if (!KeyboardState::Instance()->getKeyState(' ')) {
		pressingShoot = false;
	}

	if (KeyboardState::Instance()->getKeyState(' ') && !pressingShoot) {
		pressingShoot = true;
		shoot();
	}

}