#include "GravitationalForceGenerator.h"
#include "Entities/Particles.h"

GravitationalForceGenerator::GravitationalForceGenerator(physx::PxVec3 direction, double magnitude) : DirectionalForceGenerator(direction, magnitude) {

}

void GravitationalForceGenerator::applyForce(Particle* p) {
	p->addForce(p->getMass() * _direction * _forceMultiplier);
}