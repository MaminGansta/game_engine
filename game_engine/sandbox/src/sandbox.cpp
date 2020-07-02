
#include "engine.h"



// sfml
//#include "SFML/OpenGL.hpp"
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/System/Clock.hpp>
//#include <SFML/Window/Event.hpp>




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

