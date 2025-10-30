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
}

void Particle::changeColor(physx::PxVec4 color) {
	renderItem->color = color;
}

physx::PxVec3 Particle::getPosition() {
	return transform->p;
}