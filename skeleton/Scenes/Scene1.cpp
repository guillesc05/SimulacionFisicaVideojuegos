#include "Scene1.h"

#include <PxPhysicsAPI.h>
using namespace physx;
#include "../Entities/Particles.h"

Scene1::Scene1() : Scene() {
	for (int i = 0; i < MAX_BULLETS; i++) bullets[i] = nullptr;
}

void Scene1::start() {

}

void Scene1::shootCannon(const physx::PxTransform& camera) {
	PxVec3 velocity = camera.q.rotate(PxVec3(0.f, 0.f, -CANNON_BALL_SIMULATED_VELOCITY));

	Particle* p = new Particle(camera.p, velocity, CANNON_BALL_SIMULATED_MASS, 1.f);
	p->changeColor({ 1.f,1.f,0.f,1.f });

	shoot(p);
}

void Scene1::shootTankBullet(const physx::PxTransform& camera) {
	PxVec3 velocity = camera.q.rotate(PxVec3(0.f, 0.f, -TANK_BULLET_SIMULATED_VELOCITY));

	Particle* p = new Particle(camera.p, velocity, TANK_BULLET_SIMULATED_MASS, 1.f);
	p->changeColor({ 1.f,0.f,1.f,1.f });

	shoot(p);
}

void Scene1::shootPistolBullet(const physx::PxTransform& camera) {
	PxVec3 velocity = camera.q.rotate(PxVec3(0.f, 0.f, -PISTOL_BULLET_SIMULATED_VELOCITY));

	Particle* p = new Particle(camera.p, velocity, PISTOL_BULLET_SIMULATED_MASS, 1.f);
	p->changeColor({ 0.f,1.f,1.f,1.f });

	shoot(p);
}

void Scene1::shoot(Particle* p) {
	if (bullets[bullet_index] != nullptr) delete bullets[bullet_index];
	bullets[bullet_index] = p;
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
	case 'q':
		shootCannon(camera);
		break;
	case 'e':
		shootTankBullet(camera);
		break;
	case 'r':
		shootPistolBullet(camera);
		break;
	default:
		break;
	}
}