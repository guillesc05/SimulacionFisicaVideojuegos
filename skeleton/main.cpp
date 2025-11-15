#include <ctype.h>

#include <PxPhysicsAPI.h>
#include "Entities/Particles.h"

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Scene.h"
#include "Scenes/Scene1.h"
#include "Scenes/Scene2.h"
#include "Scene3.h"
#include "ProjectScene.h"

#include <iostream>

std::string display_text = "This is a test";


using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;

RenderItem* xAxis = nullptr;
RenderItem* yAxis = nullptr;
RenderItem* zAxis = nullptr;

Scene* currentScene = nullptr;

const float AXIS_LENGTH = 25.f;

// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	//objeto+++++++++++++++++++++++++++++++++++++++++++++++++++

	physx::PxShape* xBall = CreateShape(PxSphereGeometry(2.0f));
	xAxis = new RenderItem(xBall, new PxTransform(AXIS_LENGTH, 0, 0), Vector4(0, 1, 0, 1));
	RegisterRenderItem(xAxis);

	physx::PxShape* yBall = CreateShape(PxSphereGeometry(2.0f));
	yAxis = new RenderItem(yBall, new PxTransform(0, AXIS_LENGTH, 0), Vector4(1, 0, 0, 1));
	RegisterRenderItem(yAxis);

	physx::PxShape* zBall = CreateShape(PxSphereGeometry(2.0f));
	zAxis = new RenderItem(zBall, new PxTransform(0, 0, AXIS_LENGTH), Vector4(0, 0, 1, 1));
	RegisterRenderItem(zAxis);

	//CREAR ESCENA
	currentScene = new Scene3();
	currentScene->start();
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	currentScene->integrate(t);
	gScene->fetchResults(true);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();

	DeregisterRenderItem(xAxis);
	DeregisterRenderItem(yAxis);
	DeregisterRenderItem(zAxis);
	delete currentScene;
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	currentScene->keyPress(key, camera);
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}