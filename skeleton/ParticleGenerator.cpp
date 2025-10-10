#include "ParticleGenerator.h"
#include "Entities/Particles.h"

ParticleGenerator::ParticleGenerator(physx::PxVec3 p, physx::PxVec3 r, float d):_basePosition(p), _baseRotation(r), _baseDuration(d) {
	
}

Particle* ParticleGenerator::generateNewParticle() {
}