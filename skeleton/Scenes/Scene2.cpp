#include "Scene2.h"
#include "../ParticleSystem.h"
#include "../ParticleGenerators/UniformParticleGenerator.h"
#include "../ParticleGenerators/GaussianParticleGenerator.h"
#include "../GravitationalForceGenerator.h"

void Scene2::start() {
	auto particleSystem = new ParticleSystem(6);
	systems.push_back(particleSystem);
	particleSystem->addParticleGenerator(new UniformParticleGenerator(physx::PxVec3(100, 0, 0), physx::PxVec3(0, 0, 1), 2, 200, 0, 0.05, .1, 30));

	particleSystem->addParticleGenerator(new UniformParticleGenerator(physx::PxVec3(100, 0, 0), physx::PxVec3(0), 5, 5, 50, 1, .1, 3));
	particleSystem->addParticleGenerator(new GaussianParticleGenerator(physx::PxVec3(-100, 0, 0), physx::PxVec3(0), 5, 5, 50, 1, .1, 3));

	particleSystem->addForceGenerator(new GravitationalForceGenerator(physx::PxVec3(0.f, -9.8f, 0.f), 1.));
}