#pragma once
#include "ForceGenerator.h"
#include <unordered_map>
#include <PxPhysicsAPI.h>

class SpringForceGenerator: public ForceGenerator
{
public:
	SpringForceGenerator(double k, double restingLength);
	~SpringForceGenerator();
	void applyForce(Particle* p) override;

	void connectParticles(Particle* p1, Particle* p2);
	void anchorParticle(Particle* p1, physx::PxVec3 staticPos);

	void changeGlobalK(double newK);
	double getK();

protected:
	std::unordered_map<Particle*, std::vector<Particle*>> _connections;

	std::vector<Particle*> staticParticles;

	double _k;
	double _restingLength;
};

