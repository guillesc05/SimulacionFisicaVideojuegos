#include "PhysicsUtils.h"
#include <PxScene.h>

PhysicsUtils::PhysicsUtils():gScene(nullptr) {
}

PhysicsUtils* PhysicsUtils::Instance() {
	if (instance == nullptr) {
		instance = new PhysicsUtils();
	}
	return instance;
}

void PhysicsUtils::setScene(physx::PxScene* s) {
	gScene = s;
}

physx::PxScene* PhysicsUtils::getScene() {
	return gScene;
}
