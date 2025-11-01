#include "WindForceGenerator.h"
#include "Entities/Particles.h"

WindForceGenerator::WindForceGenerator(physx::PxVec3 direction, double magnitude, double k1, double k2) : DirectionalForceGenerator(direction, magnitude), _k1(k1), _k2(k2) {

}

void WindForceGenerator::applyForce(Particle* p) {
	const physx::PxVec3 velocityDifference = _direction * _forceMultiplier - p->getVelocity();
	const physx::PxVec3 windForce = _k1 * (velocityDifference) + _k2 * velocityDifference.magnitude() * velocityDifference;
	p->addForce(windForce);
}
