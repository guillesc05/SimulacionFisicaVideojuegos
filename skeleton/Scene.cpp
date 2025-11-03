#include "Scene.h"
#include "UpdateableObject.h"

Scene::Scene() {

}

void Scene::integrate(double t) {
	for (auto uO : updateableObjects) {
		uO->integrate(t);
	}
}

void Scene::start() {

}

Scene::~Scene() {
	for (auto uO : updateableObjects) {
		delete uO;
	}
}