#include "EscapeTheQ.h"
#include "Components/LuaScriptComponent.h"
#include "EntitySystems/PhysicsSystem.h"
#include "EntitySystems/LuaScriptSystem.h"
#include "EntitySystems/RenderingSystem.h"
#include "Input/InputEventSystem.h"
#include "Mix/Entity.h"
#include "PythonScriptComponent.h"
#include <string>

using namespace AwesomeEngine;
EscapeTheQ::EscapeTheQ(const std::wstring& name, int width, int height, bool vSync)
	: DirectXApp( name, width, height, vSync )
{

}

EscapeTheQ::~EscapeTheQ()
{
}

bool EscapeTheQ::Initialize()
{
	bool isInit = DirectXApp::Initialize();
	if (isInit)
	{
		mWorld.getSystemManager().addSystem<PhysicsSystem>();
		mWorld.getSystemManager().addSystem<LuaScriptSystem>();
		mWorld.getSystemManager().addSystem<RenderingSystem>();
	}

	return isInit;
}

void EscapeTheQ::Update(float dt)
{
	mWorld.update();

	// TODO : polish entity component system
	mWorld.getSystemManager().getSystem<PhysicsSystem>().Update(dt);
	mWorld.getSystemManager().getSystem<LuaScriptSystem>().Update(dt);
	mWorld.getSystemManager().getSystem<RenderingSystem>().Update(dt);
}

void EscapeTheQ::Render(float dt)
{

}
