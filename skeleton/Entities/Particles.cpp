#include "Particles.h"
#include <math.h>
#include <stdio.h>

Particle::Particle(physx::PxVec3 p, physx::PxVec3 v,float m,  float d):vel(v),  damping(d), mass(m), inverseMass(pow(m,-1)) {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
	transform = new physx::PxTransform(p);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
	forceVector = physx::PxVec3(0);
}

Particle::~Particle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::addForce(physx::PxVec3 forceToAdd) {
	forceVector += forceToAdd;
}

void Particle::integrate(double t) {
	physx::PxVec3 accel = forceVector * inverseMass;
	forceVector = physx::PxVec3(0.f,0.f,0.f);
	vel += accel * t;
	transform->p = transform->p + vel * t;
	vel *= pow(damping, t);

	update(t);
}

void Particle::changeColor(physx::PxVec4 color) {
	renderItem->color = color;
}

physx::PxVec3 Particle::getPosition() {
	return transform->p;
}

physx::PxVec3 Particle::getVelocity() {
	return vel;
}

float Particle::getMass() {
	return mass;
}

float Particle::getDamping() {
	return damping;
}
void Particle::setDamping(float d) {
	damping = d;
}

constexpr float PI = 22 / 7;
float eulerToRad(float e) {
	return e * (PI / 180.f);
}

float radToEuler(float r) {
	return r / (PI / 180.f);
}

physx::PxVec3 Particle::getRotation() {
	float f; physx::PxVec3 vec;
	transform->q.toRadiansAndUnitAxis(f, vec);
	return vec * radToEuler(f);
}

void Particle::setRotation(physx::PxVec3 r) {
	transform->q = physx::PxQuat(eulerToRad(r.x), physx::PxVec3(1, 0, 0));
	transform->q *= physx::PxQuat(eulerToRad(r.y), physx::PxVec3(0, 1, 0));
	transform->q *= physx::PxQuat(eulerToRad(r.z), physx::PxVec3(0, 0, 1));
}