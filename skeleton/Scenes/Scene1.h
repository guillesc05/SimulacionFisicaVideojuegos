#pragma once
#include "../Scene.h"

constexpr int MAX_BULLETS = 60;

class Scene1 : public Scene {
	Particle* bullets[MAX_BULLETS];
	int bullet_index = 0;

public:
	Scene1();
	void integrate(double d) override;
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
	void shoot(const physx::PxTransform& camera);
};