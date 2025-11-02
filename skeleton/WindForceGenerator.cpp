#include "WindForceGenerator.h"
#include "Entities/Particles.h"

WindForceGenerator::WindForceGenerator(physx::PxVec3 direction, double magnitude, double k1, double k2, physx::PxVec3 position, double radius) :
	DirectionalForceGenerator(direction, magnitude), _k1(k1), _k2(k2), _position(position), _radius(radius) {

}

physx::PxVec3 WindForceGenerator::getWindVelocity(Particle* p) {
	return _direction * _forceMultiplier;
}

void WindForceGenerator::applyForce(Particle* p) {
	if ((p->getPosition() - _position).magnitude() > _radius) return;

	const physx::PxVec3 velocityDifference = getWindVelocity(p) - p->getVelocity();
	const physx::PxVec3 windForce = _k1 * (velocityDifference) + _k2 * velocityDifference.magnitude() * velocityDifference;
	p->addForce(windForce);
}
