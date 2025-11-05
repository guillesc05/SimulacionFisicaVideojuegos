#include "ForceGenerator.h"
#include "Entities/Particles.h"

ForceGenerator::ForceGenerator(double m) :_forceMultiplier(m) {

}

void ForceGenerator::integrate(double t) {
	_time += t;
}

void ForceGenerator::setActive(bool b) {
	_active = b;
}

bool ForceGenerator::isActive() {
	return _active;
}

