#include "Scene3.h"
#include "Entities/Particles.h"
#include "ParticleSystem.h"
#include "SpringForceGenerator.h"
#include "GravitationalForceGenerator.h"
#include "FloatForceGenerator.h"
#include "WhirlwindForceGenerator.h"
#include "RubberBandForceGenerator.h"

void Scene3::start() {
	auto system = new ParticleSystem(1);
	pushUpdateableObject(system);

	whirlWind = new WhirlwindForceGenerator(1, 1, 0, physx::PxVec3(0));
	whirlWind->setActive(false);
	system->addForceGenerator(whirlWind);

	Particle* p1 = new Particle(physx::PxVec3(0, -10, 0), physx::PxVec3(0), 1, 0.8);
	system->addPermanentParticle(p1);
	Particle* p2 = new Particle(physx::PxVec3(0, 10, 0), physx::PxVec3(0), 1, 0.8);
	system->addPermanentParticle(p2);
	Particle* p3 = new Particle(physx::PxVec3(10, 0, 0), physx::PxVec3(0), 1, 0.8);
	system->addPermanentParticle(p3);
	springForceGenerator = new SpringForceGenerator(10, 10);
	system->addForceGenerator(springForceGenerator);
	springForceGenerator->connectParticles(p1, p2);
	springForceGenerator->connectParticles(p2, p3);
	springForceGenerator->connectParticles(p3, p1);

	/*
	Particle* p3 = new Particle(physx::PxVec3(0, 10, 0),physx::PxVec3(0), 1, 0.8);
	p3->changeRenderItem(CreateShape(physx::PxBoxGeometry(1.0f, 1.0f, 1.0f)));
	system->addForceGenerator(new GravitationalForceGenerator(physx::PxVec3(0, -1, 0), 9.8));
	FloatForceGenerator* floatingFG = new FloatForceGenerator(0, 1000);
	system->addPermanentParticle(p3);
	system->addForceGenerator(floatingFG);
	*/
}

void Scene3::keyPress(unsigned char key, const physx::PxTransform& camera) {
	if (key == 'q') {
		springForceGenerator->changeGlobalK(springForceGenerator->getK() + 1);
	}
	if (key == 'e') {
		springForceGenerator->changeGlobalK(springForceGenerator->getK() - 1);
	}

	if (key == 'r') {
		whirlWind->setActive(!whirlWind->isActive());
	}
}