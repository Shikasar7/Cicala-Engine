#include <Cicala.h>

#include "imgui/imgui.h"

class ExampleLayer : public Cicala::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Cicala::Input::IsKeyPressed(CC_KEY_TAB))
			CC_TRACE("Tab key is pressed(POLL)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Cicala::Event& event) override
	{
		if (event.GetEventType() == Cicala::EventType::KeyPressed)
		{
			Cicala::KeyPressedEvent& e = (Cicala::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CC_KEY_TAB)
				CC_TRACE("Tab key is pressed!(event)");
			CC_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Cicala::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Cicala::Application* Cicala::CreateApplication()
{
	return new Sandbox();
}

/*
int main() 
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}*/