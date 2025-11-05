#include "ProjectScene.h"
#include "Spaceship.h"
#include "ParticleSystem.h"
#include "WhirlwindForceGenerator.h"

void ProjectScene::start() {
	glClearColor(0, 0, 0, 1);
	ParticleSystem* pSystem = new ParticleSystem(7);
	updateableObjects.push_back(pSystem);

	
	GaussianParticleGenerator* cloudParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0), 5, 5, 250, 1, .1, 3);
	cloudParticles->setColor(physx::PxVec4(252./255., 227./255., 3./255., 1));
	pSystem->addParticleGenerator(cloudParticles);

	GaussianParticleGenerator* cloudParticles2 = new GaussianParticleGenerator(physx::PxVec3(100, 0, 100), physx::PxVec3(0), 5, 5, 300, 1, .1, 3);
	cloudParticles2->setColor(physx::PxVec4(3. / 255., 152. / 255., 253. / 255., 1));
	pSystem->addParticleGenerator(cloudParticles2);

	GaussianParticleGenerator* engineParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 15);
	engineParticles->setColor(physx::PxVec4(252. / 255., 51. / 255., 3. / 255., .5));
	pSystem->addParticleGenerator(engineParticles);

	_spaceShip = new Spaceship(physx::PxVec3(0),engineParticles);
	_spaceShip->setDamping(0.5);
	updateableObjects.push_back(_spaceShip);

	_whirlWindGenerator = new WhirlwindForceGenerator(.5, 1, 0, physx::PxVec3(0, -100, 0));
	updateableObjects.push_back(_whirlWindGenerator);
	pSystem->addForceGenerator(_whirlWindGenerator);

	_windGenerator = new WindForceGenerator(physx::PxVec3(1,0,1).getNormalized(), 200, 1, 0, physx::PxVec3(0), 1000);
	updateableObjects.push_back(_windGenerator);
	pSystem->addForceGenerator(_windGenerator);
}

void ProjectScene::keyPress(unsigned char key, const physx::PxTransform& camera) {
	switch (key) {
	case 'q':
		_whirlWindGenerator->setActive(!_whirlWindGenerator->isActive());
		break;
	case 'e':
		_windGenerator->setActive(!_windGenerator->isActive());
		break;
	}

	//DEPRECATED 
	//Ahora uso KeyboardState.h para saber continuamente si hay una tecla pulsada o no
	//_spaceShip->keyPressed(key);
}