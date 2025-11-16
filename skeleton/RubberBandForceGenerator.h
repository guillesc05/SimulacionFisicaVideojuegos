#pragma once
#include "SpringForceGenerator.h"
class RubberBandForceGenerator: public SpringForceGenerator
{
public:
	RubberBandForceGenerator(double k, double rL);
	void applyForce(Particle* p) override;
};