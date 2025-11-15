#include "Scene3.h"
#include "Entities/Particles.h"
#include "ParticleSystem.h"
#include "SpringForceGenerator.h"
#include "AnchoredSpringForceGenerator.h"
#include "GravitationalForceGenerator.h"

void Scene3::start() {
	auto system = new ParticleSystem(1);
	pushUpdateableObject(system);
	Particle* p1 = new Particle(physx::PxVec3(0, -10, 0), physx::PxVec3(0), 1, 0.8);
	Particle* p2 = new Particle(physx::PxVec3(0, 0, 0), physx::PxVec3(0), 1, 0.8);
	system->addPermanentParticle(p1);
	system->addPermanentParticle(p2);
	SpringForceGenerator* f1 = new SpringForceGenerator(200, 20, p1);
	SpringForceGenerator* f2 = new SpringForceGenerator(200, 20, p2);
	system->addForceGenerator(f1);
	system->addForceGenerator(f2);
	system->addForceGenerator(new GravitationalForceGenerator(physx::PxVec3(0, -1, 0), 9.8));
}

void Scene3::keyPress(unsigned char key, const physx::PxTransform& camera) {

}