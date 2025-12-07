#pragma once
#include "../Scene.h"

template<typename T>
class ParticleSystem;
class Scene2 :public Scene {
public:
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
};
