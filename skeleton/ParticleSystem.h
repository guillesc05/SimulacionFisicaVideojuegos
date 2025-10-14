#pragma once
#include <list>
#include "ParticleGenerator.h"
class Particle;
class ParticleSystem
{
	std::list<ParticleWithDuration> _particles;
	std::list<ParticleGenerator*> _generators;

	int _particles_per_tick=0;

public:
	void update(double t);
	void addGenerator(ParticleGenerator* gen);
	ParticleSystem(int particlesPerTick);
};