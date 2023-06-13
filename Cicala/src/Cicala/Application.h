#pragma once

#include "Core.h"

#include "Window.h"
#include "Cicala/LayerStack.h"
#include "Events/Event.h"
#include "Cicala/Events/ApplicationEvent.h"

#include "Cicala/ImGui/ImGuiLayer.h"

#include "Cicala/Renderer/Shader.h"
#include "Cicala/Renderer/Buffer.h"
#include "Cicala/Renderer/VertexArray.h"

#include "Cicala/Renderer/OrthographicCamera.h"

namespace Cicala {

	class CICALA_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application* s_Instance;
	};

	//To be defined in CLIENT (inside SandboxApp)
	Application* CreateApplication();

}