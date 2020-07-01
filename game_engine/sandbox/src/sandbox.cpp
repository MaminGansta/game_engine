
#include "engine.h"


struct Sandbox : Engine::Application
{
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Engine::Application* Engine::create_application()
{
	return new Sandbox();
}

