#pragma once
#include "Scene.h"
class Spaceship;
class ForceGenerator;
class ProjectScene: public Scene
{
	ForceGenerator* _whirlWindGenerator;
	ForceGenerator* _windGenerator;
	Spaceship* _spaceShip;

	constexpr static int NUM_ENEMIES = 5;
	constexpr static float MAX_ENEMY_SPAWN_RANGE = 3000;
public:
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
};

