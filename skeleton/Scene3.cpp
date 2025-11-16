#include "Scene3.h"
#include "Entities/Particles.h"
#include "ParticleSystem.h"
#include "SpringForceGenerator.h"
#include "GravitationalForceGenerator.h"
#include "FloatForceGenerator.h"

void Scene3::start() {
	auto system = new ParticleSystem(1);
	pushUpdateableObject(system);
	/*
	Particle* p1 = new Particle(physx::PxVec3(0, -10, 0), physx::PxVec3(0), 1, 0.8);
	system->addPermanentParticle(p1);
	SpringForceGenerator* f1 = new SpringForceGenerator();
	system->addForceGenerator(f1);

	f1->anchorParticle(p1, physx::PxVec3(0, 0, 0), 10, 20);
	f1->anchorParticle(p1, physx::PxVec3(0, -30, 0), 10, 20);
	*/
	Particle* p3 = new Particle(physx::PxVec3(0, 10, 0),physx::PxVec3(0), 1, 0.8);
	p3->changeRenderItem(CreateShape(physx::PxBoxGeometry(1.0f, 1.0f, 1.0f)));
	system->addForceGenerator(new GravitationalForceGenerator(physx::PxVec3(0, -1, 0), 9.8));
	FloatForceGenerator* floatingFG = new FloatForceGenerator(0, 1000);
	system->addPermanentParticle(p3);
	system->addForceGenerator(floatingFG);

}

void Scene3::keyPress(unsigned char key, const physx::PxTransform& camera) {

}