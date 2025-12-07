#pragma once
#include <list>
#include "ParticleGenerator.h"
#include "UpdateableObject.h"
#include "Entities/Particles.h"
#include "ForceGenerator.h"

template<typename T>
class ParticleSystem: public UpdateableObject
{
	std::list<ParticleWithAttributes> _particles;
	std::list<Particle*> _permanentParticles;
	std::list<ParticleGenerator*> _particleGenerators;
	std::list<ForceGenerator*> _forceGenerators;

	int _particles_per_tick=0;
	const double MAX_PARTICLE_DISTANCE = 500;
public:
	void addPermanentParticle(Particle* p) {
		_permanentParticles.push_back(p);
	}
	void integrate(double t) override {
		for (auto it = _particles.begin(); it != _particles.end();) {
			(*it).particle->integrate(t);
			(*it).deadTime -= t;

			for (auto forceGen : _forceGenerators) {
				if (forceGen->isActive())
					forceGen->applyForce((*it).particle);
			}

			if ((*it).deadTime <= 0 || ((*it).initialPosition - (*it).particle->getPosition()).magnitude() > MAX_PARTICLE_DISTANCE) {
				delete (*it).particle;
				it = _particles.erase(it);
			}
			else it++;
		}

		for (auto p : _permanentParticles) {
			p->integrate(t);

			for (auto forceGen : _forceGenerators) {
				if (forceGen->isActive()) forceGen->applyForce(p);
			}
		}

		for (auto gen : _particleGenerators) {
			if (!gen->isActive()) continue;
			for (int i = 0; i < _particles_per_tick / _particleGenerators.size(); i++)
				_particles.push_back(gen->generateNewParticle<T>());
		}
	}
	void addParticleGenerator(ParticleGenerator* gen) {
		_particleGenerators.push_back(gen);
	}
	void addForceGenerator(ForceGenerator* gen) {
		_forceGenerators.push_back(gen);
	}
	ParticleSystem(int particlesPerTick) : _particles_per_tick(particlesPerTick) {

	}
	~ParticleSystem() {
		for (auto particles : _particles) {
			delete particles.particle;
		}

		for (auto p : _permanentParticles) {
			delete p;
		}

		for (auto pGen : _particleGenerators) {
			delete pGen;
		}
	}
};