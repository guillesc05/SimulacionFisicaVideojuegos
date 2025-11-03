#include "ExplosionForceGenerator.h"
#include "Entities/Particles.h"

ExplosionForceGenerator::ExplosionForceGenerator(physx::PxVec3 pos, double r, double tC, double explosionForce):ForceGenerator(explosionForce),
	_position(pos), _radius(r), _timeConstant(tC)
{

}

void ExplosionForceGenerator::applyForce(Particle* p) {
	float r = (p->getPosition() - _position).magnitude();
	if (r > _radius) return;

	physx::PxVec3 res = p->getPosition() - _position;
	res *= (_forceMultiplier / pow(r, 2));
	res *= pow(exp(1.0), -(_time / _timeConstant));
	p->addForce(res);
}
