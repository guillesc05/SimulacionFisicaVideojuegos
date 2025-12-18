#include "Spaceship.h"
#include "RenderUtils.hpp"
#include "KeyboardState.h"
#include "Scene.h"
#include "CustomParticle.h"
#include "Bullet.h"
#include <cmath>
#include "PhysicsUtils.h"
#include "SpringForceGenerator.h"

#include "PlayerInfoSingleton.h"

Spaceship::Spaceship(physx::PxVec3 pos, GaussianParticleGenerator* engineParticle, ParticleSystem<CustomParticle>* bulletParticleSystem, Scene* s): PhysxParticle(pos, physx::PxVec3(0), SHIP_MASS, SHIP_DAMP), _engineParticles(engineParticle),
_scene(s), _bulletPSystem(bulletParticleSystem)
{
	changeRenderItem(CreateShape(physx::PxBoxGeometry(2.0f,2.0f, 2.0f)));

	_body->setRigidDynamicLockFlags(physx::PxRigidDynamicLockFlag::eLOCK_LINEAR_Y | physx::PxRigidDynamicLockFlag::eLOCK_ANGULAR_X | physx::PxRigidDynamicLockFlag::eLOCK_ANGULAR_Z);
	//canyon
	//_cannonBody = CreateDynamic(physx::PxTransform(physx::PxVec3(-4,0,0)));
	_cannonParticle = new CustomParticle(physx::PxVec3(4, 0, 0), physx::PxVec3(0), CANNON_MASS, CANNON_DAMP);
	_cannonParticle->changeRenderItem(CreateShape(physx::PxSphereGeometry(1)));

	//---MUELLE
	auto muelleSystem = new ParticleSystem<PhysxParticle>(0);
	s->pushUpdateableObject(muelleSystem);
	muelleSystem->addPermanentParticle(this);
	muelleSystem->addPermanentParticle(_cannonParticle);
	SpringForceGenerator* springFG = new SpringForceGenerator(10000, (getPosition() - _cannonParticle->getPosition()).magnitude());
	springFG->connectParticles(_cannonParticle, this);
	muelleSystem->addForceGenerator(springFG);
}

void Spaceship::update(double t) {
	updateCamera();
	keyPressed(t);


	_engineParticles->setBasePosition(getPosition());
	_engineParticles->setBaseDirection(-getRotationDirection());

	//--We clamp the cannon distance from the spaceship so it doesnt break
	auto cannonDir = (getPosition() - _cannonParticle->getPosition()).getNormalized();
	auto cannonDistanceMag = (getPosition() - _cannonParticle->getPosition()).magnitude();
	if (cannonDistanceMag > MAX_CANNON_DISTANCE) cannonDistanceMag = MAX_CANNON_DISTANCE;
	_cannonParticle->setPosition(getPosition() + cannonDir * cannonDistanceMag);

	//--move cannon to the rotation
	auto distanceMag = (getPosition() - _cannonParticle->getPosition()).magnitude();


	_cannonParticle->setPosition(getPosition() + getRotationDirection() * distanceMag);


	//actualizar singleton con posicion del playerr
	PlayerInfoSingleton::Instance()->setPlayerPos(getPosition());
}

void Spaceship::updateCamera() {
	physx::PxVec3 camPos;
	physx::PxVec3 camDir;

	if (cameraOnTop) {
		camPos = getPosition() + physx::PxVec3(20, 100, 0);
		camDir = (getPosition() - GetCamera()->getEye()).getNormalized();
	}
	else {
		camPos = getPosition() + physx::PxVec3(0.01, 2.5, 0);
		camDir = getRotationDirection();
	}

	GetCamera()->setEye(camPos);
	GetCamera()->setDir(camDir);
	
}

void Spaceship::shoot() {
	physx::PxVec3 dir;
	if (cameraOnTop) dir = getRotationDirection();
	else dir = GetCamera()->getDir();

	Particle* p = new Bullet(getPosition() + dir * 8, getVelocity() + dir * SHOOT_VELOCITY,_bulletPSystem, _body->getGlobalPose().q);
	_bulletPSystem->addPermanentParticle(p);

	//aplicar fuerza al cannon
	_cannonParticle->addForce(-dir * BACKLASH_MAGNITUDE);
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
		addRotation(physx::PxVec3(0, ROTATION_VELOCITY, 0)*t);
	}
	else if (KeyboardState::Instance()->getKeyState('k')) {
		addRotation(physx::PxVec3(0, -ROTATION_VELOCITY, 0)*t);
	}
	else {
		addRotation(physx::PxVec3(0, 0, 0));
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