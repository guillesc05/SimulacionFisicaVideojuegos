#include "Scene.h"
#include "Entities/Particles.h"
#include "ParticleSystem.h"

Scene::Scene() {

}

void Scene::integrate(double t) {
	for (auto particle : particles) {
		particle->integrate(t);
	}

	for (auto system : systems) {
		system->update(t);
	}
}

void Scene::start() {

}

Scene::~Scene() {
	for (auto particle : particles) {
		delete particle;
	}
}