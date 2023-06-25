#pragma once

#include "Core.h"

#include "Window.h"
#include "Cicala/LayerStack.h"
#include "Events/Event.h"
#include "Cicala/Events/ApplicationEvent.h"

#include "Cicala/Core/Timestep.h"

#include "Cicala/ImGui/ImGuiLayer.h"

namespace Cicala {

	class Application
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

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	//To be defined in CLIENT (inside SandboxApp)
	Application* CreateApplication();

}