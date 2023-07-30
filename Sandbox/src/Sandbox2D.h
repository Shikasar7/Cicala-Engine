#pragma once

#include "Cicala.h"

class Sandbox2D : public Cicala::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Cicala::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Cicala::Event& e) override;
private:
	Cicala::OrthographicCameraController m_CameraController;

	// Temp
	Cicala::Ref<Cicala::VertexArray> m_SquareVA;
	Cicala::Ref<Cicala::Shader> m_FlatColorShader;

	Cicala::Ref<Cicala::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};