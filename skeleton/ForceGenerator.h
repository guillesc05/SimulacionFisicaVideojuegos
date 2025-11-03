#pragma once

#include "UpdateableObject.h"

class Particle;
class ForceGenerator: public UpdateableObject
{
public:
	ForceGenerator(double forceMultiplier);
	virtual void applyForce(Particle* p) =0;
	void integrate(double t) override;
protected:
	double _time =0;
	double _forceMultiplier;
};

