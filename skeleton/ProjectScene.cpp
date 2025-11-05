#include "ProjectScene.h"
#include "Spaceship.h"
#include "ParticleSystem.h"
#include "WhirlwindForceGenerator.h"

void ProjectScene::start() {
	ParticleSystem* pSystem = new ParticleSystem(10);
	updateableObjects.push_back(pSystem);

	GaussianParticleGenerator* cloudParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0), 5, 5, 250, 1, .1, 3);
	pSystem->addParticleGenerator(cloudParticles);

	GaussianParticleGenerator* engineParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 15);
	pSystem->addParticleGenerator(engineParticles);

	_spaceShip = new Spaceship(physx::PxVec3(0),engineParticles);
	_spaceShip->setDamping(0.5);
	updateableObjects.push_back(_spaceShip);

	auto whirlwindForceGenerator = new WhirlwindForceGenerator(.5, 1, 0, physx::PxVec3(0, -100, 0));
	updateableObjects.push_back(whirlwindForceGenerator);
	pSystem->addForceGenerator(whirlwindForceGenerator);
}

void ProjectScene::keyPress(unsigned char key, const physx::PxTransform& camera) {
	//DEPRECATED 
	//Ahora uso KeyboardState.h para saber continuamente si hay una tecla pulsada o no
	//_spaceShip->keyPressed(key);
}