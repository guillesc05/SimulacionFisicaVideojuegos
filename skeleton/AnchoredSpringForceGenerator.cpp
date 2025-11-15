#include "AnchoredSpringForceGenerator.h"
#include "Entities/Particles.h"

AnchoredSpringForceGenerator::AnchoredSpringForceGenerator(double k, double resting, physx::PxVec3 v): SpringForceGenerator(k, resting, nullptr) {
	_other = new Particle(v);
}

AnchoredSpringForceGenerator::~AnchoredSpringForceGenerator() {
	delete _other;
}