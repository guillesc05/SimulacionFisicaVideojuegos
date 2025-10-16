#include "Particles.h"
#include <math.h>
#include <stdio.h>

Particle::Particle(physx::PxVec3 p, physx::PxVec3 v,float m, physx::PxVec3 a, float d):vel(v), accel(a), damping(d), mass(m) {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
	transform = new physx::PxTransform(p);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

Particle::~Particle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::integrate(double t) {
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