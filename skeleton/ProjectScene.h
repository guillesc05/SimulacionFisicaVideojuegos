#pragma once
#include "Scene.h"
class Spaceship;
class ForceGenerator;
class ProjectScene: public Scene
{
	ForceGenerator* _whirlWindGenerator;
	ForceGenerator* _windGenerator;
	Spaceship* _spaceShip;
public:
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
};

