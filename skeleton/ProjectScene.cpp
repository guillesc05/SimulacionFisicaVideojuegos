#include "ProjectScene.h"
#include "Spaceship.h"
#include "ParticleSystem.h"

void ProjectScene::start() {
	ParticleSystem* pSystem = new ParticleSystem(6);
	updateableObjects.push_back(pSystem);

	GaussianParticleGenerator* cloudParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0), 5, 5, 150, 1, .1, 3);
	pSystem->addParticleGenerator(cloudParticles);

	GaussianParticleGenerator* engineParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 15);
	pSystem->addParticleGenerator(engineParticles);

	_spaceShip = new Spaceship(physx::PxVec3(0),engineParticles);
	_spaceShip->setDamping(0.5);
	updateableObjects.push_back(_spaceShip);
}

void ProjectScene::keyPress(unsigned char key, const physx::PxTransform& camera) {
	_spaceShip->keyPressed(key);
}