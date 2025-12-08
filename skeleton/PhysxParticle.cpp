#include "PhysxParticle.h"
#include <math.h>
#include <stdio.h>
#include "RenderUtils.hpp"
#include "PhysicsUtils.h"


PhysxParticle::PhysxParticle(physx::PxVec3 pos, physx::PxVec3 vel, float mass, float damp): Particle(){

	_body = CreateDynamic(physx::PxTransform(pos));
	_body->setLinearDamping(damp);

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(2.0f)), _body, Vector4(1, 1, 1, 1));
	_body->attachShape(*renderItem->shape);

	physx::PxRigidBodyExt::setMassAndUpdateInertia(*_body, mass);
	_body->setLinearVelocity(vel);

	PhysicsUtils::Instance()->getScene()->addActor(*_body);
}

PhysxParticle::~PhysxParticle() {
	DeregisterRenderItem(renderItem);
	delete renderItem;
	
	PhysicsUtils::Instance()->getScene()->removeActor(*_body);
}

void PhysxParticle::addForce(physx::PxVec3 forceToAdd) {
	_body->addForce(forceToAdd);
}

void PhysxParticle::integrate(double t) {
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
	return _body->getLinearDamping();
}

void PhysxParticle::setDamping(float d) {
	_body->setLinearDamping(d);
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
	_body->getGlobalPose().q.toRadiansAndUnitAxis(f, vec);
	return vec * PhysxParticleOperations::radToEuler(f);
}

void PhysxParticle::setRotation(physx::PxVec3 r) {
	physx::PxTransform tr = _body->getGlobalPose();
	tr.q = physx::PxQuat(PhysxParticleOperations::eulerToRad(r.x), physx::PxVec3(1, 0, 0));
	tr.q *= physx::PxQuat(PhysxParticleOperations::eulerToRad(r.y), physx::PxVec3(0, 1, 0));
	tr.q *= physx::PxQuat(PhysxParticleOperations::eulerToRad(r.z), physx::PxVec3(0, 0, 1));
	_body->setGlobalPose(tr);
}

physx::PxVec3 PhysxParticle::getRotationDirection() {
	return _body->getGlobalPose().q.rotate(physx::PxVec3(1, 0, 0));
}

void PhysxParticle::changeColor(physx::PxVec4 color) {
	renderItem->color = color;
}

void PhysxParticle::changeRenderItem(physx::PxShape* shape) {
	auto prevRI = renderItem;
	auto prevMass = _body->getMass();
	renderItem = new RenderItem(shape, _body, Vector4(1, 1, 1, 1));
	_body->attachShape(*renderItem->shape);
	_body->detachShape(*prevRI->shape);
	DeregisterRenderItem(prevRI);

	physx::PxRigidBodyExt::setMassAndUpdateInertia(*_body, prevMass);
}