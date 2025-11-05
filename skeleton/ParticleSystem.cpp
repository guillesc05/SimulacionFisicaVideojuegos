#include "ParticleSystem.h"
#include "Entities/Particles.h"
#include "ForceGenerator.h"

ParticleSystem::ParticleSystem(int p): _particles_per_tick(p) {

}

ParticleSystem::~ParticleSystem() {
	for (auto particles : _particles) {
		delete particles.particle;
	}

	for (auto pGen : _particleGenerators) {
		delete pGen;
	}
}

void ParticleSystem::addParticleGenerator(ParticleGenerator* gen) {
	_particleGenerators.push_back(gen);
}

void ParticleSystem::addForceGenerator(ForceGenerator* gen) {
	_forceGenerators.push_back(gen);
}

void ParticleSystem::integrate(double t) {
	for (auto it = _particles.begin(); it != _particles.end();) {
		(*it).particle->integrate(t);
		(*it).deadTime -= t;

		for (auto forceGen : _forceGenerators) {
			forceGen->applyForce((*it).particle);
		}

		if ((*it).deadTime <= 0 || ((*it).initialPosition - (*it).particle->getPosition()).magnitude() > MAX_PARTICLE_DISTANCE) {
			delete (*it).particle;
			it = _particles.erase(it);
		}
		else it++;
	}

	for (auto gen : _particleGenerators) {
		if (!gen->isActive()) continue;
		for(int i =0; i < _particles_per_tick/_particleGenerators.size(); i++)
		_particles.push_back(gen->generateNewParticle());
	}

}