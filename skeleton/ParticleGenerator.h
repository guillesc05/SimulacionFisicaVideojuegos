#pragma once
#include <PxPhysicsAPI.h>
#include <random>
class Particle;

struct ParticleWithAttributes {
	Particle* particle;
	double deadTime;
	physx::PxVec3 initialPosition;
	bool operator==(const ParticleWithAttributes& r)const& {
		return particle == r.particle;
	}
};

class ParticleGenerator
{
public:
	ParticleGenerator(physx::PxVec3 position, physx::PxVec3 rotation, double duration, double velocityModule);

	template <typename T>
	ParticleWithAttributes generateNewParticle() {
		auto pos = getNewParticlePosition();
		Particle* p = new T(pos, getNewParticleDirection().getNormalized() * getNewParticleVelocityModule(), 1.0, 0.9f);
		p->changeColor(_color);
		return { p, getNewParticleDuration(), pos };
	}

	physx::PxVec3 getBasePosition();
	physx::PxVec3 getBaseDirection();
	double getBaseDuration();
	double getBaseVelocity();

	void setBasePosition(physx::PxVec3);
	void setBaseDirection(physx::PxVec3);
	void setBaseDuration(double d);
	void setBaseVelocity(double d);

	void setActive(bool b);
	bool isActive();

	void setColor(physx::PxVec4 col);
protected:
	physx::PxVec3 _basePosition;
	physx::PxVec3 _baseDirection;
	double _baseDuration;
	double _baseVelocity;

	bool canGenerate = true;
	physx::PxVec4 _color = physx::PxVec4(1);

	

	virtual physx::PxVec3 getNewParticlePosition();
	virtual physx::PxVec3 getNewParticleDirection();
	virtual double getNewParticleDuration();
	virtual double getNewParticleVelocityModule();

	
};

