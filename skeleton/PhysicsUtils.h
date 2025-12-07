#pragma once

namespace physx {
	class PxScene;
}

class PhysicsUtils {
public:
	~PhysicsUtils();

	static PhysicsUtils* Instance();
	void setScene(physx::PxScene* s);
	physx::PxScene* getScene();
private:
	PhysicsUtils();
	physx::PxScene* gScene;
	static PhysicsUtils* instance;
};
