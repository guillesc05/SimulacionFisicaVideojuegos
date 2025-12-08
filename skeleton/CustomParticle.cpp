#include "CustomParticle.h"
#include <math.h>
#include <stdio.h>
#include "OperationUtils.h"

CustomParticle::CustomParticle(physx::PxVec3 p, physx::PxVec3 v, float m, float d) :vel(v), damping(d), mass(m), inverseMass(pow(m, -1)) {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
	transform = new physx::PxTransform(p);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
	forceVector = physx::PxVec3(0);
}

CustomParticle::~CustomParticle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void CustomParticle::addForce(physx::PxVec3 forceToAdd) {
	forceVector += forceToAdd;
}

void CustomParticle::integrate(double t) {
	physx::PxVec3 accel = forceVector * inverseMass;
	forceVector = physx::PxVec3(0.f, 0.f, 0.f);
	vel += accel * t;
	transform->p = transform->p + vel * t;
	vel *= pow(damping, t);

	update(t);
}


void CustomParticle::changeColor(physx::PxVec4 color) {
	renderItem->color = color;
}

void CustomParticle::changeRenderItem(physx::PxShape* shape) {
	DeregisterRenderItem(renderItem);
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

physx::PxVec3 CustomParticle::getPosition() {
	return transform->p;
}

physx::PxVec3 CustomParticle::getVelocity() {
	return vel;
}

float CustomParticle::getMass() {
	return mass;
}

float CustomParticle::getDamping() {
	return damping;
}

void CustomParticle::setDamping(float d) {
	damping = d;
}

physx::PxVec3 CustomParticle::getRotation() {
	float f; physx::PxVec3 vec;
	transform->q.toRadiansAndUnitAxis(f, vec);
	return vec * radToEuler(f);
}

void CustomParticle::setRotation(physx::PxVec3 r) {
	transform->q = physx::PxQuat(eulerToRad(r.x), physx::PxVec3(1, 0, 0));
	transform->q *= physx::PxQuat(eulerToRad(r.y), physx::PxVec3(0, 1, 0));
	transform->q *= physx::PxQuat(eulerToRad(r.z), physx::PxVec3(0, 0, 1));
}

physx::PxVec3 CustomParticle::getRotationDirection() {
	return transform->q.rotate(physx::PxVec3(1, 0, 0));
}