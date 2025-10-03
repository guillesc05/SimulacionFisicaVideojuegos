#include "Scene.h"
#include "Entities/Particles.h"

Scene::Scene() {

}

void Scene::integrate(double t) {
	for (auto particle : particles) {
		particle->integrate(t);
	}
}

void Scene::start() {

}

Scene::~Scene() {
	for (auto particle : particles) {
		delete particle;
	}
}