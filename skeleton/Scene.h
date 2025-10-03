#pragma once
#include <vector>

class Particle;
class Scene
{
public:
	Scene();
	void integrate(double t);

	virtual void start();
	virtual ~Scene();
protected:

	std::vector<Particle*> particles;
};

