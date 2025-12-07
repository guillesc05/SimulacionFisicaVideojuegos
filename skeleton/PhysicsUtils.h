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
	static PhysicsUtils* instance;
	physx::PxScene* gScene;
};
