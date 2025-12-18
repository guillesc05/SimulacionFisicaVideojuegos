#include "GameInfoSingleton.h"
#include "Spaceship.h"
GameInfoSingleton* GameInfoSingleton::instance = nullptr;

GameInfoSingleton::GameInfoSingleton() {
	_playerPosition = physx::PxVec3(0);
}

GameInfoSingleton::~GameInfoSingleton() {

}

void GameInfoSingleton::setNumberOfEnemies(int num) {
	_enemyPositions = std::vector<physx::PxVec3>(num);
	currentEnemies = num;
	display_text = "Current enemies: " + std::to_string(currentEnemies);
}

void GameInfoSingleton::enemyKilled(int index) {
	currentEnemies--;

	//notificar player de que x enemy ha muerto
	_player->enemyKilled(index);

	//cambiar de texto
	if (currentEnemies > 0)
		display_text = "Current enemies: " + std::to_string(currentEnemies);
	else display_text = "YOU WON!";
}

void GameInfoSingleton::playerKilled() {
	//cambiar de texto
	display_text = "YOU LOSE!";
}

void GameInfoSingleton::registerPlayer(Spaceship* p) {
	_player = p;
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