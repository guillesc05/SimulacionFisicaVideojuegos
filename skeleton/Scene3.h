#pragma once
#include "Scene.h"

class SpringForceGenerator;
class WhirlwindForceGenerator;
class ParticleSystem;
class Scene3 :public Scene {
public:
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
private:
	ParticleSystem* particleSystem;
	SpringForceGenerator* springForceGenerator;
	WhirlwindForceGenerator* whirlWind;
};

