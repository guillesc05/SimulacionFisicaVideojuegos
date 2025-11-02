#include "WhirlwindForceGenerator.h"
#include "Entities/Particles.h"

WhirlwindForceGenerator::WhirlwindForceGenerator(double magnitude, double k1, double k2, physx::PxVec3 position):
WindForceGenerator(physx::PxVec3(0), magnitude, k1, k2, position, INFINITY){

}

physx::PxVec3 WhirlwindForceGenerator::getWindVelocity(Particle* p) {
	auto particlePos = p->getPosition();
	physx::PxVec3 direction = physx::PxVec3(-(particlePos.z - _position.z), 50 - (particlePos.y - _position.y), particlePos.x - _position.x);

	return direction * _forceMultiplier;
}