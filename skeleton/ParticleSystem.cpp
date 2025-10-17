#include "ParticleSystem.h"
#include "Entities/Particles.h"

ParticleSystem::ParticleSystem(int p): _particles_per_tick(p) {

}

void ParticleSystem::addGenerator(ParticleGenerator* gen) {
	_generators.push_back(gen);
}

void ParticleSystem::update(double t) {
	for (auto it = _particles.begin(); it != _particles.end();) {
		(*it).particle->integrate(t);
		(*it).deadTime -= t;

		if ((*it).deadTime <= 0 || ((*it).initialPosition - (*it).particle->getPosition()).magnitude() > MAX_PARTICLE_DISTANCE) {
			delete (*it).particle;
			it = _particles.erase(it);
		}
		else it++;
	}

	for (auto gen : _generators) {
		for(int i =0; i < _particles_per_tick/_generators.size(); i++)
		_particles.push_back(gen->generateNewParticle());
	}

}