#include "Scene2.h"
#include "../ParticleSystem.h"
#include "../ParticleGenerator.h"

void Scene2::start() {
	auto particleSystem = new ParticleSystem(5);
	systems.push_back(particleSystem);
	particleSystem->addGenerator(new ParticleGenerator(physx::PxVec3(0), physx::PxVec3(0,0,1), 3., 30));

}