#pragma once
#include "ForceGenerator.h"
class FloatForceGenerator: public ForceGenerator
{
public:
	FloatForceGenerator(double liquidHeight, double liquidDensity);

	void applyForce(Particle* p) override;
private:
	double _liquidHeight;
	double _liquidDensity;
};

