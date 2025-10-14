#include "Scene2.h"
#include "../ParticleSystem.h"
#include "../ParticleGenerators/GaussianParticleGenerator.h"

void Scene2::start() {
	auto particleSystem = new ParticleSystem(2);
	systems.push_back(particleSystem);
	particleSystem->addGenerator(new GaussianParticleGenerator());
}