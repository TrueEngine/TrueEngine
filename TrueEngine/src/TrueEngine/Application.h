#pragma once

#include "Core.h"

namespace TrueEngine {
	class TRUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
