#pragma once
#include "Scene.h"
class ProjectScene: public Scene
{
public:
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
};

