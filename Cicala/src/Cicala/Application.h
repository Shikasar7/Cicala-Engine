#pragma once

#include "Core.h"

namespace Cicala {

	class CICALA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT (inside SandboxApp)
	Application* CreateApplication();

}