#include "Particles.h"

Particle::Particle(physx::PxVec3 p, physx::PxVec3 v):pos(p), vel(v) {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
	renderItem = new RenderItem(shape, new physx::PxTransform(0, 0, 0), Vector4(1, 1, 1, 1));
	RegisterRenderItem(renderItem);
}

Particle::~Particle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void Particle::integrate(double t) {

}