#include "CubeRenderingSystem.h"

#include "Render\Camera.h"
#include <DirectXMath.h>

using namespace DirectX;

namespace AwesomeEngine
{

	CubeRenderingSystem::CubeRenderingSystem()
	{
		requireComponent<CubeComponent>();
	}

	CubeRenderingSystem::~CubeRenderingSystem()
	{
	}

	void CubeRenderingSystem::Update(float delta, Camera* camera)
	{
		for (auto& e : getEntities())
		{
		}
	}

	void CubeRenderingSystem::Render(float delta, std::shared_ptr<CommandList> commandList, Camera* camera)
	{
		if (!camera)
			return;

		XMMATRIX viewMatrix = camera->get_ViewMatrix();
		XMMATRIX projectionMatrix = viewMatrix * camera->get_ProjectionMatrix();
		for (auto& e : getEntities())
		{
			if (e.hasComponent<CubeComponent>())
			{
				auto& renderItem = e.getComponent<CubeComponent>();
				renderItem.SetViewMatrix(viewMatrix);
				renderItem.SetProjectionMatrix(projectionMatrix);
				renderItem.OnRender(commandList);
			}
		}
	}
}