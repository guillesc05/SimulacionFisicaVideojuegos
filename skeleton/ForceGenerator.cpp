#include "ForceGenerator.h"
#include "Entities/Particles.h"

ForceGenerator::ForceGenerator(double m) :_forceMultiplier(m) {

}

void ForceGenerator::integrate(double t) {
	_time += t;
}

