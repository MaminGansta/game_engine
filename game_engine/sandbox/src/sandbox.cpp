
#include "engine.h"




struct Sandbox : Engine::Application
{
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

	//void run()
	//{
	//	while (true)
	//	{
	//
	//	}
	//}
};


Engine::Application* Engine::create_application()
{
	return new Sandbox();
}

