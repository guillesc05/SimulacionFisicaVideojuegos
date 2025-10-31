#include "DirectionalForceGenerator.h"
#include "Entities/Particles.h"

DirectionalForceGenerator::DirectionalForceGenerator(physx::PxVec3 dir, double mag) : _direction(dir), ForceGenerator(mag) {

}

void DirectionalForceGenerator::applyForce(Particle* p) {
	p->addForce(_direction * _forceMultiplier);
}