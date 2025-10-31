#pragma once
#include <list>
#include "ParticleGenerator.h"
class Particle;
class ForceGenerator;
class ParticleSystem
{
	std::list<ParticleWithAttributes> _particles;
	std::list<ParticleGenerator*> _particleGenerators;
	std::list<ForceGenerator*> _forceGenerators;

	int _particles_per_tick=0;
	const double MAX_PARTICLE_DISTANCE = 500;
public:
	void update(double t);
	void addParticleGenerator(ParticleGenerator* gen);
	void addForceGenerator(ForceGenerator* gen);
	ParticleSystem(int particlesPerTick);
};