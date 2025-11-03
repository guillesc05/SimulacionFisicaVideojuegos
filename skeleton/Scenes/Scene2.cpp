#include "Scene2.h"
#include "../ParticleSystem.h"
#include "../ParticleGenerators/UniformParticleGenerator.h"
#include "../ParticleGenerators/GaussianParticleGenerator.h"
#include "../GravitationalForceGenerator.h"
#include "../WindForceGenerator.h"
#include "../WhirlwindForceGenerator.h"
#include "../ExplosionForceGenerator.h"

void Scene2::start() {
	particleSystem = new ParticleSystem(6);
	updateableObjects.push_back(particleSystem);
	particleSystem->addParticleGenerator(new UniformParticleGenerator(physx::PxVec3(100, 0, 0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 30));

	particleSystem->addParticleGenerator(new UniformParticleGenerator(physx::PxVec3(100, 0, 0), physx::PxVec3(0), 5, 5, 50, 1, .1, 3));
	particleSystem->addParticleGenerator(new GaussianParticleGenerator(physx::PxVec3(-100, 0, 0), physx::PxVec3(0), 5, 5, 50, 1, .1, 3));

	//auto gravitationalForce = new GravitationalForceGenerator(physx::PxVec3(0.f, -9.8f, 0.f), 1.);
	//auto whirlwindForceGenerator = new WhirlwindForceGenerator(1, 1, 0, physx::PxVec3(100));
	auto explosion = new ExplosionForceGenerator(physx::PxVec3(0, 0, 0), 100, 1, 10000);

	//updateableObjects.push_back(gravitationalForce);
	//updateableObjects.push_back(whirlwindForceGenerator);
	updateableObjects.push_back(explosion);

	//particleSystem->addForceGenerator(gravitationalForce);
	//particleSystem->addForceGenerator(new WindForceGenerator(physx::PxVec3(1.f, 0.f, 0.f), 100, 1, 0, physx::PxVec3(0), 200));
	//particleSystem->addForceGenerator(whirlwindForceGenerator);
	particleSystem->addForceGenerator(explosion);
}

void Scene2::keyPress(unsigned char key, const physx::PxTransform& camera) {
	if (key == 'g') {
		auto explosion = new ExplosionForceGenerator(physx::PxVec3(0, 0, 0), 100, 1, 10000);
		updateableObjects.push_back(explosion);
		particleSystem->addForceGenerator(explosion);
	}
}