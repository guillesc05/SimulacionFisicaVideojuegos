#pragma once

#include "UpdateableObject.h"

class Particle;
class ForceGenerator: public UpdateableObject
{
public:
	ForceGenerator(double forceMultiplier);
	virtual void applyForce(Particle* p) =0;
	void integrate(double t) override;

	void setActive(bool b);
	bool isActive();
protected:
	double _time =0;
	double _forceMultiplier;

	bool _active = true;
};

