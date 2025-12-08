#pragma once
#include <PxRigidBody.h>
#include "RenderUtils.hpp"
class StaticBody
{
public:
	StaticBody(physx::PxVec3 pos, float xScale = 1, float yScale = 1, float zScale = 1);
	~StaticBody();

	void setPosition(physx::PxVec3 pos);
	void setRotation(physx::PxVec3 r);
protected:
	physx::PxRigidStatic* _body;
	RenderItem* renderItem;
};

