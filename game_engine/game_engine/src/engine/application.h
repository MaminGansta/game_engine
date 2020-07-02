#pragma once

#include "core.h"

namespace Engine
{
	struct ENGINE_API Application
	{
		Application();
		virtual ~Application();

		virtual void run();
	};

	Application* create_application();
}