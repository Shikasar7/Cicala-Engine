#pragma once

#include "Core.h"

#include "Window.h"
#include "Cicala/LayerStack.h"
#include "Events/Event.h"
#include "Cicala/Events/ApplicationEvent.h"



namespace Cicala {

	class CICALA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	//To be defined in CLIENT (inside SandboxApp)
	Application* CreateApplication();

}