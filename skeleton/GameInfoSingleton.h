#pragma once
#include <PxPhysicsAPI.h>
#include <vector>

class Spaceship;
class GameInfoSingleton
{
public:
	~GameInfoSingleton();

	static GameInfoSingleton* Instance();

	physx::PxVec3 getPlayerPos();
	std::vector<physx::PxVec3> getEnemiesPos();

	void setEnemyPos(int index, physx::PxVec3 pos);
	void setPlayerPos(physx::PxVec3 p);

	void enemyKilled(int index);
	void playerKilled();

	void registerPlayer(Spaceship* p);

	void setNumberOfEnemies(int num);
private:
	GameInfoSingleton();
	static GameInfoSingleton* instance;

	physx::PxVec3 _playerPosition;

	std::vector<physx::PxVec3> _enemyPositions;

	int currentEnemies = 0;

	Spaceship* _player;
};

