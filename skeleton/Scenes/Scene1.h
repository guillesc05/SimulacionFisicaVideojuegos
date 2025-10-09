#pragma once
#include "../Scene.h"

constexpr int MAX_BULLETS = 60;

constexpr float CANNON_BALL_REAL_MASS = 150.f;
constexpr float CANNON_BALL_REAL_VELOCITY = 250.f;
constexpr float CANNON_BALL_SIMULATED_VELOCITY = 10.f;
const float CANNON_BALL_SIMULATED_MASS = CANNON_BALL_REAL_MASS * pow(CANNON_BALL_REAL_VELOCITY / CANNON_BALL_SIMULATED_VELOCITY, 2);

constexpr float TANK_BULLET_REAL_MASS = 15.f;
constexpr float TANK_BULLET_REAL_VELOCITY = 1800.f;
constexpr float TANK_BULLET_SIMULATED_VELOCITY = 20.f;
const float TANK_BULLET_SIMULATED_MASS = TANK_BULLET_REAL_MASS * pow(TANK_BULLET_REAL_VELOCITY / TANK_BULLET_SIMULATED_VELOCITY, 2);

constexpr float PISTOL_BULLET_REAL_MASS = .230f;
constexpr float PISTOL_BULLET_REAL_VELOCITY = 330.f;
constexpr float PISTOL_BULLET_SIMULATED_VELOCITY = 25.f;
const float PISTOL_BULLET_SIMULATED_MASS = PISTOL_BULLET_REAL_MASS * pow(PISTOL_BULLET_REAL_VELOCITY / PISTOL_BULLET_SIMULATED_VELOCITY, 2);


class Scene1 : public Scene {
	Particle* bullets[MAX_BULLETS];
	int bullet_index = 0;

public:
	Scene1();
	void integrate(double d) override;
	void start() override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
	void shoot(Particle* p);

	void shootCannon(const physx::PxTransform& camera);
	void shootPistolBullet(const physx::PxTransform& camera);
	void shootTankBullet(const physx::PxTransform& camera);

};