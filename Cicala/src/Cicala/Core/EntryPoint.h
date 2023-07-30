#pragma once

#ifdef  CC_PLATFORM_WINDOWS

extern Cicala::Application* Cicala::CreateApplication();

int main(int argc, char** argv)
{
	Cicala::Log::Init();
	CC_CORE_WARN("Initialized Log!");
	int a = 5;
	CC_INFO("Hello! Var={0}",a);

	auto app = Cicala::CreateApplication();
	app->Run();
	delete app;
}
#endif //  CC_PLATFORM_WINDOWS
