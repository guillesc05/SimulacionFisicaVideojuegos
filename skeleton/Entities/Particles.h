#pragma once
#include <PxPhysicsAPI.h>
#include "../RenderUtils.hpp"
#include "../UpdateableObject.h"
//CLASE ABSTRACTA
class Particle: public UpdateableObject {
public:
	virtual void changeColor(physx::PxVec4 color)=0;
	virtual void changeRenderItem(physx::PxShape* shape)=0;

	virtual void integrate(double t) override =0;
	virtual void addForce(physx::PxVec3 force) =0;

	virtual physx::PxVec3 getPosition() =0;
	virtual physx::PxVec3 getVelocity() =0;

	virtual float getDamping() =0;
	virtual void setDamping(float d) =0;
	virtual void update(double t) = 0;

	virtual float getMass() =0;

	virtual physx::PxVec3 getRotation() =0;
	virtual void setRotation(physx::PxVec3 r) =0;

	virtual physx::PxVec3 getRotationDirection() =0;

protected:
	RenderItem* renderItem;
};
