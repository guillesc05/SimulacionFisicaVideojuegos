#pragma once
#include "Scene.h"

#include <string>
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
	void onCollision(physx::PxActor* p1, physx::PxActor* p2) override;
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
};

