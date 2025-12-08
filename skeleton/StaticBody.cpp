#include "StaticBody.h"
#include "RenderUtils.hpp"
#include "PhysicsUtils.h"
#include <PxShape.h>
#include "OperationUtils.h"

StaticBody::StaticBody(physx::PxVec3 pos, float xScale, float yScale, float zScale) {
	_body = CreateStatic(physx::PxTransform(pos));
	auto shape = CreateShape(physx::PxBoxGeometry(xScale, yScale, zScale));
	_body->attachShape(*shape);

	renderItem = new RenderItem(shape, _body, physx::PxVec4(1));

	PhysicsUtils::Instance()->getScene()->addActor(*_body);
}
StaticBody::~StaticBody() {
	PhysicsUtils::Instance()->getScene()->removeActor(*_body);
}

void StaticBody::setPosition(physx::PxVec3 pos) {
	auto tr = _body->getGlobalPose();
	tr.p = pos;

	_body->setGlobalPose(tr);
}

void StaticBody::setRotation(physx::PxVec3 r) {
	physx::PxTransform tr = _body->getGlobalPose();
	tr.q = physx::PxQuat(eulerToRad(r.x), physx::PxVec3(1, 0, 0));
	tr.q *= physx::PxQuat(eulerToRad(r.y), physx::PxVec3(0, 1, 0));
	tr.q *= physx::PxQuat(eulerToRad(r.z), physx::PxVec3(0, 0, 1));
	_body->setGlobalPose(tr);
}