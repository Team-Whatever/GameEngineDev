#include "ConeRenderingSystem.h"

#include "Render/Camera.h"
#include "Components/ConeComponent.h"
#include "Components/TransformComponent.h"
#include <DirectXMath.h>

using namespace DirectX;

namespace AwesomeEngine
{

	ConeRenderingSystem::ConeRenderingSystem()
	{
		requireComponent<ConeComponent>();
		requireComponent<TransformComponent>();
	}

	ConeRenderingSystem::~ConeRenderingSystem()
	{
	}

	void ConeRenderingSystem::Update(float delta, Camera* camera)
	{
		for (auto& e : getEntities())
		{
		}
	}

	void ConeRenderingSystem::Render(float delta, std::shared_ptr<CommandList> commandList, Camera* camera)
	{
		if (!camera)
			return;

		XMMATRIX viewMatrix = camera->get_ViewMatrix();
		XMMATRIX projectionMatrix = viewMatrix * camera->get_ProjectionMatrix();
		for (auto& e : getEntities())
		{
			if (e.hasComponent<ConeComponent>())
			{
				auto& renderItem = e.getComponent<ConeComponent>();
				auto& transform = e.getComponent<TransformComponent>();

				renderItem.SetViewMatrix(viewMatrix);
				renderItem.SetProjectionMatrix(projectionMatrix);
				renderItem.SetTranslation(transform.position);
				renderItem.SetRotation(transform.rotation);
				renderItem.SetScale(transform.scale);
				renderItem.OnRender(commandList);
			}
		}
	}
}