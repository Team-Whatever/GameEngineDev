#include "CylinderRenderingSystem.h"

#include "Render/Camera.h"
#include "Components/CylinderComponent.h"
#include "Components/TransformComponent.h"
#include <DirectXMath.h>

using namespace DirectX;

namespace AwesomeEngine
{

	CylinderRenderingSystem::CylinderRenderingSystem()
	{
		requireComponent<CylinderComponent>();
		requireComponent<TransformComponent>();
	}

	CylinderRenderingSystem::~CylinderRenderingSystem()
	{
	}

	void CylinderRenderingSystem::Update(float delta, Camera* camera)
	{
		for (auto& e : getEntities())
		{
		}
	}

	void CylinderRenderingSystem::Render(float delta, std::shared_ptr<CommandList> commandList, Camera* camera)
	{
		if (!camera)
			return;

		XMMATRIX viewMatrix = camera->get_ViewMatrix();
		XMMATRIX projectionMatrix = viewMatrix * camera->get_ProjectionMatrix();
		for (auto& e : getEntities())
		{
			if (e.hasComponent<CylinderComponent>())
			{
				auto& renderItem = e.getComponent<CylinderComponent>();
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