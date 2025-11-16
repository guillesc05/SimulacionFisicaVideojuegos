#include "RubberBandForceGenerator.h"

#include "Entities/Particles.h"

RubberBandForceGenerator::RubberBandForceGenerator(double k, double rL): SpringForceGenerator(k, rL) {

}

void RubberBandForceGenerator::applyForce(Particle* p) {

	for (auto connectedParticle : _connections[p]) {
		physx::PxVec3 relative_pos_vector = connectedParticle->getPosition() - p->getPosition();
		physx::PxVec3 force;

		const float length = relative_pos_vector.normalize();
		const float delta_x = length - _restingLength;

		if (delta_x < 0) continue;

		force = relative_pos_vector * delta_x * _k;

		p->addForce(force);
	}
}