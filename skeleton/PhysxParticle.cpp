#include "PhysxParticle.h"
#include <math.h>
#include <stdio.h>
#include "RenderUtils.hpp"
#include "PhysicsUtils.h"


PhysxParticle::PhysxParticle(physx::PxVec3 p, float m, float d): Particle(){
	_body = CreateDynamic(physx::PxTransform(p));
	_body->setMass(m);

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(2.0f)), _body, Vector4(1, 1, 1, 1));
	_body->attachShape(*renderItem->shape);

	PhysicsUtils::Instance()->getScene()->addActor(*_body);
}

PhysxParticle::~PhysxParticle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
}

void PhysxParticle::addForce(physx::PxVec3 forceToAdd) {
	_body->addForce(forceToAdd);
}

void PhysxParticle::integrate(double t) {
	/*physx::PxVec3 accel = forceVector * inverseMass;
	forceVector = physx::PxVec3(0.f, 0.f, 0.f);
	vel += accel * t;
	transform->p = transform->p + vel * t;
	vel *= pow(damping, t);
	*/
	update(t);
}

physx::PxVec3 PhysxParticle::getPosition() {
	return _body->getWorldBounds().getCenter();
}

physx::PxVec3 PhysxParticle::getVelocity() {
	return _body->getLinearVelocity();
}

float PhysxParticle::getMass() {
	return _body->getMass();
}

float PhysxParticle::getDamping() {
	return 1;
}

void PhysxParticle::setDamping(float d) {
	//damping = d;
}

namespace PhysxParticleOperations {
	constexpr float PI = 22 / 7;
	float eulerToRad(float e) {
		return e * (PI / 180.f);
	}

	float radToEuler(float r) {
		return r / (PI / 180.f);
	}

};

physx::PxVec3 PhysxParticle::getRotation() {
	float f; physx::PxVec3 vec;
	renderItem->transform->q.toRadiansAndUnitAxis(f, vec);
	return vec * PhysxParticleOperations::radToEuler(f);
}

void PhysxParticle::setRotation(physx::PxVec3 r) {
	/*renderItem->transform->q = physx::PxQuat(eulerToRad(r.x), physx::PxVec3(1, 0, 0));
	renderItem->transform->q *= physx::PxQuat(eulerToRad(r.y), physx::PxVec3(0, 1, 0));
	renderItem->transform->q *= physx::PxQuat(eulerToRad(r.z), physx::PxVec3(0, 0, 1));
	*/
}

physx::PxVec3 PhysxParticle::getRotationDirection() {
	return renderItem->transform->q.rotate(physx::PxVec3(1, 0, 0));
}

void PhysxParticle::changeColor(physx::PxVec4 color) {
	renderItem->color = color;
}

void PhysxParticle::changeRenderItem(physx::PxShape* shape) {
	auto prevRI = renderItem;
	renderItem = new RenderItem(shape, _body, Vector4(1, 1, 1, 1));
	_body->attachShape(*renderItem->shape);
	_body->detachShape(*prevRI->shape);
	DeregisterRenderItem(prevRI);
}