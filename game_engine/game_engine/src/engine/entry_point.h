#pragma once


extern Engine::Application* create_application();


int main(int argc, char** argv)
{
	Engine::Log::init();

	LOG_INFO("INFO VAR = {0} {0:X}", 17);
	LOG_TRACE("TRACE");
	LOG_ERROR("ERROR");
	LOG_WARN("WARN");

	LOG_CORE_WARN("WARN");


	auto app = Engine::create_application();
	app->run();
	delete app;
	return 0;
}