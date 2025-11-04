#include "ProjectScene.h"
#include "Spaceship.h"

void ProjectScene::start() {
	_spaceShip = new Spaceship();
	_spaceShip->setDamping(0.1);
	updateableObjects.push_back(_spaceShip);
}

void ProjectScene::keyPress(unsigned char key, const physx::PxTransform& camera) {
	_spaceShip->keyPressed(key);
}