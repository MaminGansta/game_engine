#pragma once


extern Engine::Application* create_application();


int main(int argc, char** argv)
{
	Engine::Log::init();

	Engine::Application* app = Engine::create_application();
	app->run();
	
	delete app;
	return 0;
}