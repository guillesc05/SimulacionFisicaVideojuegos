#pragma once
#include "ForceGenerator.h"
#include <unordered_map>
#include <PxPhysicsAPI.h>

struct SpringAttributes {
	Particle* connectedParticle;
	double k;
	double restingLength;
	SpringAttributes(Particle* p, double _k, double _rL) : connectedParticle(p), k(_k), restingLength(_rL) {

	}
};

class SpringForceGenerator: public ForceGenerator
{
public:
	SpringForceGenerator();
	~SpringForceGenerator();
	void applyForce(Particle* p) override;

	void connectParticles(Particle* p1, Particle* p2, double k, double resting_length);
	void connectParticles(Particle* p1, physx::PxVec3 staticPos, double k, double resting_length);

protected:
	std::unordered_map<Particle*, std::vector<SpringAttributes>> _connections;

	std::vector<Particle*> staticParticles;
};

