#include <Cicala.h>

class Sandbox : public Cicala::Application
{
public:
	Sandbox()
	{

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