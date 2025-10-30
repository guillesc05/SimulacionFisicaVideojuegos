#pragma once

class Particle;
class ForceGenerator
{
	ForceGenerator(double forceMultiplier);
public:
	virtual void applyForce(Particle* p) =0;
protected:

	double _forceMultiplier;
};

