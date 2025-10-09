#pragma once
#include <vector>
#include <PxPhysicsAPI.h>

class Particle;
class Scene
{
public:
	Scene();
	virtual void integrate(double t);

	virtual void start();
	virtual void keyPress(unsigned char key, const physx::PxTransform& camera){}
	virtual ~Scene();
protected:

	std::vector<Particle*> particles;
};

