#include "Scene1.h"

#include <PxPhysicsAPI.h>
using namespace physx;
#include "../Entities/Particles.h"

Scene1::Scene1() : Scene() {
	for (int i = 0; i < MAX_BULLETS; i++) bullets[i] = nullptr;
}

void Scene1::start() {
	Particle* p = new Particle(PxVec3(0.f), PxVec3(0, 10.0f, 0.f), PxVec3(0.0f, -9.8f, 0.0f), 0.8f);
	particles.push_back(p);
}

void Scene1::shoot(const physx::PxTransform& camera) {
	if (bullets[bullet_index] != nullptr) delete bullets[bullet_index];
	bullets[bullet_index] = new Particle(camera.p,camera.q.rotate(PxVec3(0.f, 0.f, -100.f)), PxVec3(0.0f, -9.8f, 0.0f), 0.8f);
	bullet_index++;
	if (bullet_index == MAX_BULLETS) bullet_index = 0;
}

void Scene1::integrate(double t) {
	Scene::integrate(t);
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullets[i] != nullptr) bullets[i]->integrate(t);
	}
}

void Scene1::keyPress(unsigned char key, const PxTransform& camera) {
	switch (key) {
	case 'e':
		shoot(camera);
		break;
	default:
		break;
	}
}