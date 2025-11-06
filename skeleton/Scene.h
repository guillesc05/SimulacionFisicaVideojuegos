#pragma once
#include <vector>
#include <PxPhysicsAPI.h>

class Particle;

class UpdateableObject;
class Scene
{
public:
	Scene();
	virtual void integrate(double t);

	virtual void start();
	virtual void keyPress(unsigned char key, const physx::PxTransform& camera){}
	virtual ~Scene();
	void pushUpdateableObject(UpdateableObject* o);
protected:

	std::vector<UpdateableObject*> updateableObjects;
	std::vector<UpdateableObject*> pendingObjects;
};

