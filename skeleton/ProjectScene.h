#pragma once
#include "Scene.h"
class Spaceship;
class ProjectScene: public Scene
{
	Spaceship* _spaceShip;
public:
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
};

