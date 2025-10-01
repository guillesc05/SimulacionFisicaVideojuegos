#include "Particles.h"

Particle::Particle(physx::PxVec3 p, physx::PxVec3 v, physx::PxVec3 a):vel(v), accel(a) {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
	transform = new physx::PxTransform(p);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
	RegisterRenderItem(renderItem);
}

Particle::~Particle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::integrate(double t) {
	vel += accel * t;
	transform->p += vel * t;
}