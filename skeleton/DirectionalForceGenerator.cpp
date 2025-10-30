#include "DirectionalForceGenerator.h"
#include "Entities/Particles.h"

void DirectionalForceGenerator::applyForce(Particle* p) {
	p->addForce(_direction * _forceMultiplier);
}