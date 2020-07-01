#pragma once


extern Engine::Application* create_application();


int main(int argc, char** argv)
{
	auto app = Engine::create_application();
	app->run();
	delete app;
	return 0;
}