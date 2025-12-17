#include "PlayerInfoSingleton.h"
PlayerInfoSingleton* PlayerInfoSingleton::instance = nullptr;

PlayerInfoSingleton::PlayerInfoSingleton() {
	_playerPosition = physx::PxVec3(0);
}

PlayerInfoSingleton::~PlayerInfoSingleton() {

}

PlayerInfoSingleton* PlayerInfoSingleton::Instance() {
	if (instance == nullptr) {
		instance = new PlayerInfoSingleton();
	}
	return instance;
}

physx::PxVec3 PlayerInfoSingleton::getPlayerPos() {
	return _playerPosition;
}

void PlayerInfoSingleton::setPlayerPos(physx::PxVec3 p) {
	_playerPosition = p;
}