#include "SpringForceGenerator.h"
#include "Entities/Particles.h"


SpringForceGenerator::SpringForceGenerator():ForceGenerator(0) {

}

SpringForceGenerator::~SpringForceGenerator() {
	for (auto p : staticParticles) {
		delete p;
	}
}

void SpringForceGenerator::connectParticles(Particle* p1, Particle* p2, double k, double restingLength) {
	_connections[p1].push_back(SpringAttributes(p2, k, restingLength));
	_connections[p2].push_back(SpringAttributes(p1, k, restingLength));
}

void SpringForceGenerator::connectParticles(Particle* p1, physx::PxVec3 static_position, double k, double restingLength) {
	Particle* staticP = new Particle(static_position);
	staticParticles.push_back(staticP);
	_connections[p1].push_back(SpringAttributes(staticP, k, restingLength));
}

void SpringForceGenerator::applyForce(Particle* p) {

	for (auto springAttributes : _connections[p]) {
		physx::PxVec3 relative_pos_vector = springAttributes.connectedParticle->getPosition() - p->getPosition();
		physx::PxVec3 force;

		const float length = relative_pos_vector.normalize();
		const float delta_x = length - springAttributes.restingLength;

		force = relative_pos_vector * delta_x * springAttributes.k;

		p->addForce(force);
	}

	
}
