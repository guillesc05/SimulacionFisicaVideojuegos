#pragma once
#include <list>
#include "ParticleGenerator.h"
#include "UpdateableObject.h"
class Particle;
class ForceGenerator;
class ParticleSystem: public UpdateableObject
{
	std::list<ParticleWithAttributes> _particles;
	std::list<Particle*> _permanentParticles;
	std::list<ParticleGenerator*> _particleGenerators;
	std::list<ForceGenerator*> _forceGenerators;

	int _particles_per_tick=0;
	const double MAX_PARTICLE_DISTANCE = 500;
public:
	void addPermanentParticle(Particle* p);
	void integrate(double t) override;
	void addParticleGenerator(ParticleGenerator* gen);
	void addForceGenerator(ForceGenerator* gen);
	ParticleSystem(int particlesPerTick);
	~ParticleSystem();
};