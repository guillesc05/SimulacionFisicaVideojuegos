#include "SpringForceGenerator.h"
#include "Entities/Particles.h"


SpringForceGenerator::SpringForceGenerator(double k, double resting_length, Particle* other):ForceGenerator(0), _k(k), _resting_length(resting_length), _other(other) {

}

void SpringForceGenerator::applyForce(Particle* p) {
	if (p == _other) return;

	physx::PxVec3 relative_pos_vector = _other->getPosition() - p->getPosition();
	physx::PxVec3 force;

	const float length = relative_pos_vector.normalize();
	const float delta_x = length - _resting_length;

	force = relative_pos_vector * delta_x * _k;

	p->addForce(force);
}
