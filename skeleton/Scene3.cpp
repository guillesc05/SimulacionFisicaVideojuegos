#include "Scene3.h"
#include "Entities/Particles.h"
#include "ParticleSystem.h"
#include "SpringForceGenerator.h"
#include "AnchoredSpringForceGenerator.h"

void Scene3::start() {
	auto system = new ParticleSystem(1);
	pushUpdateableObject(system);
	Particle* p1 = new Particle(physx::PxVec3(0, 10, 0), physx::PxVec3(0), 1, 0.8);
	system->addPermanentParticle(p1);
	SpringForceGenerator* f1 = new AnchoredSpringForceGenerator(10, 20, physx::PxVec3(0));
	system->addForceGenerator(f1);
}

void Scene3::keyPress(unsigned char key, const physx::PxTransform& camera) {

}