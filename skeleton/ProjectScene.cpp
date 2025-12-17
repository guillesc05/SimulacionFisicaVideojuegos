#include "ProjectScene.h"
#include "Spaceship.h"
#include "ParticleSystem.h"
#include "WhirlwindForceGenerator.h"
#include "CustomParticle.h"
#include "PhysicsUtils.h"

#include "Enemy.h"

#include <random>

void ProjectScene::start() {


	GetCamera()->disableCameraInput();
	glClearColor(0, 0, 0, 1);
	PhysicsUtils::Instance()->getScene()->setGravity(physx::PxVec3(0));
	ParticleSystem<CustomParticle>* pSystem = new ParticleSystem<CustomParticle>(3);
	updateableObjects.push_back(pSystem);

	//--GENERADORES DE PARTICULAS
	GaussianParticleGenerator* cloudParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0), 5, 5, 250, 1, .1, 3);
	cloudParticles->setColor(physx::PxVec4(252./255., 227./255., 3./255., 1));
	pSystem->addParticleGenerator(cloudParticles);

	GaussianParticleGenerator* cloudParticles2 = new GaussianParticleGenerator(physx::PxVec3(100, 0, 100), physx::PxVec3(0), 5, 5, 300, 1, .1, 3);
	cloudParticles2->setColor(physx::PxVec4(3. / 255., 152. / 255., 253. / 255., 1));
	pSystem->addParticleGenerator(cloudParticles2);

	GaussianParticleGenerator* engineParticles = new GaussianParticleGenerator(physx::PxVec3(0, 0, 0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 15);
	engineParticles->setColor(physx::PxVec4(252. / 255., 51. / 255., 3. / 255., .5));
	pSystem->addParticleGenerator(engineParticles);
	
	//--GENERADORES DE FUERZA
	_whirlWindGenerator = new WhirlwindForceGenerator(.5, 1, 0, physx::PxVec3(0, -100, 0));
	updateableObjects.push_back(_whirlWindGenerator);
	pSystem->addForceGenerator(_whirlWindGenerator);

	_windGenerator = new WindForceGenerator(physx::PxVec3(1, 0, 1).getNormalized(), 200, 1, 0, physx::PxVec3(0), 1000);
	updateableObjects.push_back(_windGenerator);
	pSystem->addForceGenerator(_windGenerator);


	//-NAVE
	ParticleSystem<CustomParticle>* bulletParticleSystem = new ParticleSystem<CustomParticle>(1);

	updateableObjects.push_back(bulletParticleSystem);
	_spaceShip = new Spaceship(physx::PxVec3(0),engineParticles, bulletParticleSystem ,this);
	_spaceShip->setDamping(0.5);

	//--ENEMIES
	ParticleSystem<CustomParticle>* enemyParticleSystem = new ParticleSystem<CustomParticle>(1);
	updateableObjects.push_back(enemyParticleSystem);

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(-MAX_ENEMY_SPAWN_RANGE, MAX_ENEMY_SPAWN_RANGE); // define the range

	for (int i = 0; i < NUM_ENEMIES; i++) {
		auto enemy = new Enemy(physx::PxVec3(distr(gen), 0, distr(gen)), enemyParticleSystem, this);
		enemyParticleSystem->addPermanentParticle(enemy);
	}
	
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