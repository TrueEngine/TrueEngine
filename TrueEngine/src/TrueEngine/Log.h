#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace TrueEngine {

	class TRUE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define TE_CORE_TRACE(...) ::TrueEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_CORE_INFO(...) ::TrueEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TE_CORE_WARN(...) ::TrueEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_CORE_ERROR(...) ::TrueEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TE_CORE_FATAL(...) ::TrueEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define TE_TRACE(...) ::TrueEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_INFO(...) ::TrueEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TE_WARN(...) ::TrueEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_ERROR(...) ::TrueEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TE_FATAL(...) ::TrueEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)