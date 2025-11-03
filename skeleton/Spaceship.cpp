#include "Spaceship.h"

Spaceship::Spaceship(physx::PxVec3 pos, physx::PxVec3 vel, float mass, float damp): Particle(pos, vel, mass, damp) {
	DeregisterRenderItem(renderItem);
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(2.0f,2.0f, 2.0f));
	renderItem = new RenderItem(shape, transform, Vector4(1, 1, 1, 1));
}

void Spaceship::keyPressed(unsigned char c) {
	switch (c) {
	case 'w':
		break;
	case 'a':
		break;
	case 's':
		break;
	case 'd':
		break;
	}
}