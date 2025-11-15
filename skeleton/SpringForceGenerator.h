#pragma once
#include "ForceGenerator.h"
class SpringForceGenerator: public ForceGenerator
{
public:
	SpringForceGenerator(double k, double resting_length, Particle* other);
	void applyForce(Particle* p) override;

protected:
	double _k;
	double _resting_length;
	Particle* _other;
};

