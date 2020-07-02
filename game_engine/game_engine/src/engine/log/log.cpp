
#include "log.h"


namespace Engine
{
	std::shared_ptr<spdlog::logger> Log::client_logger;
	std::shared_ptr<spdlog::logger> Log::core_logger;

	Log::Log() {}

	Log::~Log() {}

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		core_logger = spdlog::stdout_color_mt("Engine");
		core_logger->set_level(spdlog::level::trace);
		
		client_logger = spdlog::stdout_color_mt("APP");
		client_logger->set_level(spdlog::level::trace);
	}
}