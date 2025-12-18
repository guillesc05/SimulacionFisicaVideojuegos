#include "GameInfoSingleton.h"
GameInfoSingleton* GameInfoSingleton::instance = nullptr;

GameInfoSingleton::GameInfoSingleton() {
	_playerPosition = physx::PxVec3(0);
}

GameInfoSingleton::~GameInfoSingleton() {

}

void GameInfoSingleton::setNumberOfEnemies(int num) {
	_enemyPositions = std::vector<physx::PxVec3>(num);
}

GameInfoSingleton* GameInfoSingleton::Instance() {
	if (instance == nullptr) {
		instance = new GameInfoSingleton();
	}
	return instance;
}

physx::PxVec3 GameInfoSingleton::getPlayerPos() {
	return _playerPosition;
}

void GameInfoSingleton::setPlayerPos(physx::PxVec3 p) {
	_playerPosition = p;
}

std::vector<physx::PxVec3> GameInfoSingleton::getEnemiesPos() {
	return _enemyPositions;
}

void GameInfoSingleton::setEnemyPos(int index, physx::PxVec3 pos) {
	_enemyPositions[index] = pos;
}