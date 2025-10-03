#include "Scene1.h"

#include <PxPhysicsAPI.h>
using namespace physx;
#include "../Entities/Particles.h"

Scene1::Scene1() : Scene() {

}

void Scene1::start() {
	Particle* p = new Particle(PxVec3(0.f), PxVec3(0, 10.0f, 0.f), PxVec3(0.0f, -9.8f, 0.0f), 0.8f);
	particles.push_back(p);
}