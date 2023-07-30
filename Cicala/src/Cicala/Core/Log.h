#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
 
namespace Cicala {

	class CICALA_API Log
	{
	public:
		//初始化函数和记录器。Initial function and 2 kinds of Loggers
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// macros for Core Logger
#define CC_CORE_TRACE(...)    ::Cicala::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CC_CORE_INFO(...)     ::Cicala::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CC_CORE_WARN(...)     ::Cicala::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CC_CORE_ERROR(...)    ::Cicala::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CC_CORE_FATAL(...)    ::Cicala::Log::GetCoreLogger()->critical(__VA_ARGS__)

// macros for Client Logger
#define CC_TRACE(...)    ::Cicala::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CC_INFO(...)     ::Cicala::Log::GetClientLogger()->info(__VA_ARGS__)
#define CC_WARN(...)     ::Cicala::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CC_ERROR(...)    ::Cicala::Log::GetClientLogger()->error(__VA_ARGS__)
#define CC_FATAL(...)    ::Cicala::Log::GetClientLogger()->critical(__VA_ARGS__)

