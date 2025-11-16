#include "FloatForceGenerator.h"
#include "Entities/Particles.h"

FloatForceGenerator::FloatForceGenerator(double lH, double lD) : ForceGenerator(0), _liquidHeight(lH), _liquidDensity(lD) {

}

void FloatForceGenerator::applyForce(Particle* p) {
	double h = p->getPosition().y;
	double h0 = _liquidHeight;
	double height = 1.0f;
	double immersed;

	if (h - h0 > height * 0.5) {
		immersed = 0.0;
	}
	else if (h0 - h > height * 0.5) {
		immersed = 1.0;
	}
	else {
		immersed = (h0 - h) / height + 0.5;
	}

	double yForce = _liquidDensity * 1 * immersed * 9.8;
	p->addForce(physx::PxVec3(0, yForce, 0));
}
