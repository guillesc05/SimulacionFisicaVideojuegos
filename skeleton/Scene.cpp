#include "Scene.h"
#include "UpdateableObject.h"

Scene::Scene() {

}

void Scene::integrate(double t) {
	for (auto uO : updateableObjects) {
		uO->integrate(t);
	}
	for (auto uO : pendingObjects) {
		updateableObjects.push_back(uO);
	}
	pendingObjects.clear();
}

void Scene::start() {

}

void Scene::pushUpdateableObject(UpdateableObject* p) {
	pendingObjects.push_back(p);
}

Scene::~Scene() {
	for (auto uO : updateableObjects) {
		delete uO;
	}
}