#pragma once

#include <memory>

#include "./Core.h"
#include <spdlog/spdlog.h>


namespace Ghost
{
    class GHOST_API Log
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


#define GHOST_CORE_TRACE(...)   ::Ghost::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GHOST_CORE_INFO(...)    ::Ghost::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GHOST_CORE_WARN(...)    ::Ghost::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GHOST_CORE_ERROR(...)   ::Ghost::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GHOST_CORE_FATAL(...)   ::Ghost::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define GHOST_TRACE(...)        ::Ghost::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GHOST_INFO(...)         ::Ghost::Log::GetClientLogger()->info(__VA_ARGS__)
#define GHOST_WARN(...)         ::Ghost::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GHOST_ERROR(...)        ::Ghost::Log::GetClientLogger()->error(__VA_ARGS__)
#define GHOST_FATAL(...)        ::Ghost::Log::GetClientLogger()->fatal(__VA_ARGS__)