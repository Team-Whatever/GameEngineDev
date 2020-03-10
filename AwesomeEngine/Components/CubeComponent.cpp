#include "CubeComponent.h"
#include "Render/Material.h"
#include "Render/Camera.h"
#include "Application.h"
#include "CommandQueue.h"

using namespace DirectX;
namespace AwesomeEngine
{
	CubeComponent::CubeComponent()
		: CubeComponent( L"" )
	{
	}

	CubeComponent::CubeComponent(std::wstring textureName)
		: RenderComponent(textureName)
	{
	}

	void CubeComponent::Initialize(std::shared_ptr<CommandList> commandList)
	{
		RenderComponent::Initialize(commandList);
		m_Mesh = Mesh::CreateCube(*commandList);
	}


	void CubeComponent::Update(float delta)
	{
		//// Draw a cube
		//translationMatrix = XMMatrixTranslation(4.0f, 4.0f, 4.0f);
		//rotationMatrix = XMMatrixRotationY(XMConvertToRadians(45.0f));
		//scaleMatrix = XMMatrixScaling(4.0f, 8.0f, 4.0f);
		//worldMatrix = scaleMatrix * rotationMatrix * translationMatrix;
	}

	void CubeComponent::OnRender(std::shared_ptr<CommandList> commandList)
	{
		if (!m_Initialized)
		{
			Initialize(commandList);
		}
		else
		{
			// Draw the earth sphere
			XMMATRIX translationMatrix = XMMatrixTranslation(4.0f, 4.0f, 4.0f);
			XMMATRIX rotationMatrix = XMMatrixRotationY(XMConvertToRadians(45.0f));
			XMMATRIX scaleMatrix = XMMatrixScaling(4.0f, 8.0f, 4.0f);
			XMMATRIX worldMatrix = scaleMatrix * rotationMatrix * translationMatrix;

			Mat matrices;
			ComputeMatrices(worldMatrix, mViewMatrix, mProjectionMatrix, matrices);

			commandList->SetGraphicsDynamicConstantBuffer(RootParameters::MatricesCB, matrices);
			commandList->SetGraphicsDynamicConstantBuffer(RootParameters::MaterialCB, Material::White);
			commandList->SetShaderResourceView(RootParameters::Textures, 0, m_Texture, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);

			m_Mesh->Render(*commandList);
		}
	}

}