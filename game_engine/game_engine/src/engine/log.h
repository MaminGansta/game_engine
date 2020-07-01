#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine
{
	struct ENGINE_API Log
	{
		static std::shared_ptr<spdlog::logger> client_logger;
		static std::shared_ptr<spdlog::logger> core_logger;

		Log();
		
		~Log();

		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_logger() { return client_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger; }
	};
}

#define LOG_CORE_TRACE(...) ::Engine::Log::get_core_logger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)  ::Engine::Log::get_core_logger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)  ::Engine::Log::get_core_logger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::Engine::Log::get_core_logger()->error(__VA_ARGS__)


#define LOG_TRACE(...) ::Engine::Log::get_logger()->trace(__VA_ARGS__)
#define LOG_INFO(...)  ::Engine::Log::get_logger()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::Engine::Log::get_logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Engine::Log::get_logger()->error(__VA_ARGS__)
