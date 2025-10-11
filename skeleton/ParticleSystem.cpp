#include "ParticleSystem.h"
#include "Entities/Particles.h"

void ParticleSystem::update(double t) {
	for (auto p : _particles) {
		p.particle->integrate(t);
		p.deadTime -= t;

		if (p.deadTime <= 0) _particles.remove(p);
	}


	for (auto gen : _generators) {
		_particles.push_back(gen->generateNewParticle());
	}

}