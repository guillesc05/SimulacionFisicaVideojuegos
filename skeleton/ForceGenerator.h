#pragma once

class Particle;
class ForceGenerator
{
public:
	ForceGenerator(double forceMultiplier);
	virtual void applyForce(Particle* p) =0;
protected:

	double _forceMultiplier;
};

