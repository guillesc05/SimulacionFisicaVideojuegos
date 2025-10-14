#include "ParticleSystem.h"
#include "Entities/Particles.h"

ParticleSystem::ParticleSystem(int p): _particles_per_tick(p) {

}

void ParticleSystem::addGenerator(ParticleGenerator* gen) {
	_generators.push_back(gen);
}

void ParticleSystem::update(double t) {
	std::list<ParticleWithDuration> toErase;
	for (ParticleWithDuration& p : _particles) {
		p.particle->integrate(t);
		p.deadTime -= t;

		if (p.deadTime <= 0) {
			toErase.push_back(p);
		}
	}
	for (auto& p : toErase) {
		_particles.remove(p);
		delete p.particle;
	}


	for (auto gen : _generators) {
		for(int i =0; i < _particles_per_tick/_generators.size(); i++)
		_particles.push_back(gen->generateNewParticle());
	}

}