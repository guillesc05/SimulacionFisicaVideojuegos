#include "SpringForceGenerator.h"
#include "Entities/Particles.h"
#include "CustomParticle.h"

SpringForceGenerator::SpringForceGenerator(double k, double restingLength):ForceGenerator(0), _k(k), _restingLength(restingLength) {

}

SpringForceGenerator::~SpringForceGenerator() {
	for (auto p : staticParticles) {
		delete p;
	}
}

void SpringForceGenerator::connectParticles(Particle* p1, Particle* p2) {
	_connections[p1].push_back(p2);
	_connections[p2].push_back(p1);
}

void SpringForceGenerator::anchorParticle(Particle* p1, physx::PxVec3 static_position) {
	Particle* staticP = new CustomParticle(static_position);
	staticP->changeRenderItem(CreateShape(physx::PxBoxGeometry(2.0f, 2.0f, 2.0f)));
	staticParticles.push_back(staticP);
	_connections[p1].push_back(staticP);
}

void SpringForceGenerator::changeGlobalK(double newK) {
	_k = newK;
}

double SpringForceGenerator::getK() { return _k; }

void SpringForceGenerator::applyForce(Particle* p) {

	for (auto connectedParticle : _connections[p]) {
		physx::PxVec3 relative_pos_vector = connectedParticle->getPosition() - p->getPosition();
		physx::PxVec3 force;

		const float length = relative_pos_vector.normalize();
		const float delta_x = length - _restingLength;

		force = relative_pos_vector * delta_x * _k;

		p->addForce(force);
	}
}

void SpringForceGenerator::clearAllConnections() {
	_connections.clear();
	staticParticles.clear();
}
