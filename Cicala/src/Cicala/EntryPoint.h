#pragma once

#ifdef  CC_PLATFORM_WINDOWS

extern Cicala::Application* Cicala::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cicala::CreateApplication();
	app->Run();
	delete app;
}
#endif //  CC_PLATFORM_WINDOWS
