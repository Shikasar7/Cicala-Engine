#include <Cicala.h>

class ExampleLayer : public Cicala::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		CC_INFO("ExampleLayer::Update");

	}

	void OnEvent(Cicala::Event& event) override
	{
		CC_TRACE("{0}", event);
	}
};

class Sandbox : public Cicala::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Cicala::ImGuiLayer());
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