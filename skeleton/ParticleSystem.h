#pragma once
#include <list>
#include "ParticleGenerator.h"
class Particle;
class ParticleSystem
{
	std::list<ParticleWithDuration> _particles;
	std::list<ParticleGenerator*> _generators;

public:
	void update(double t);
};