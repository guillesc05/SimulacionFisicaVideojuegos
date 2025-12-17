#pragma once
#include <PxPhysicsAPI.h>

class PlayerInfoSingleton
{
public:
	~PlayerInfoSingleton();

	static PlayerInfoSingleton* Instance();

	physx::PxVec3 getPlayerPos();
	void setPlayerPos(physx::PxVec3 p);
private:
	PlayerInfoSingleton();
	static PlayerInfoSingleton* instance;

	physx::PxVec3 _playerPosition;
};

