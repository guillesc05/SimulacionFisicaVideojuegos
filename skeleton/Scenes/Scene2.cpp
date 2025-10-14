#include "Scene2.h"
#include "../ParticleSystem.h"
#include "../ParticleGenerators/GaussianParticleGenerator.h"

void Scene2::start() {
	auto particleSystem = new ParticleSystem(3);
	systems.push_back(particleSystem);
	particleSystem->addGenerator(new GaussianParticleGenerator(physx::PxVec3(0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 30));
	particleSystem->addGenerator(new GaussianParticleGenerator(physx::PxVec3(0), physx::PxVec3(0), 5, 10, 100, .5, .1, 3));
}