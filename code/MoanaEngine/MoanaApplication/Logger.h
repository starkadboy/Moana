#pragma once

#pragma warning(push, 0)        
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)

#include "Core.h"

namespace Moana {
	class MOA_API_IE Logger
	{
	public:
		Logger() { Init(); };
		~Logger() {};

		enum class eLogLevel {
			LOG_TRACE,
			LOG_INFO,
			LOG_WARNING,
			LOG_ERROR,
			LOG_FATAL,
			LOG_NUM
		};

		//To add a new logger, simply add a new eEngineLoggers + new logger's name into m_EngineLoggers
		enum class eEngineLoggers {
			LOGGER_CORE,
			LOGGER_NUM
		};

		enum class eClientLoggers {
			LOGGER_MAIN,
			LOGGER_NUM
		};

		void Init();

		static void CreateLoggerModule();
		static std::shared_ptr<spdlog::logger> GetEngineLogger(eEngineLoggers logger);
		static std::shared_ptr<spdlog::logger> GetClientLogger(eClientLoggers logger);
	private:
		static const char* m_EngineLoggers[(int)eEngineLoggers::LOGGER_NUM];
		static const char* m_ClientLoggers[(int)eClientLoggers::LOGGER_NUM];

		std::string m_ownLoggerName{ "MOANA_LOGGER" };
		std::shared_ptr<spdlog::logger> m_pSelfLogger;
		std::shared_ptr<spdlog::logger> m_vSpdEngineLoggers[(int)eEngineLoggers::LOGGER_NUM];
		std::shared_ptr<spdlog::logger> m_vSpdClientLoggers[(int)eClientLoggers::LOGGER_NUM];

		static std::shared_ptr<Logger> s_pLogger;
	};
}

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define MOA_LOG_TRACE_ENGINE(LOGGER_NAME,...) ::Moana::Logger::GetEngineLogger(LOGGER_NAME)->trace(__VA_ARGS__)
#define MOA_LOG_INFO_ENGINE(LOGGER_NAME,...) ::Moana::Logger::GetEngineLogger(LOGGER_NAME)->info(__VA_ARGS__)
#define MOA_LOG_WARN_ENGINE(LOGGER_NAME,...) ::Moana::Logger::GetEngineLogger(LOGGER_NAME)->warn(__VA_ARGS__)
#define MOA_LOG_ERROR_ENGINE(LOGGER_NAME,...) ::Moana::Logger::GetEngineLogger(LOGGER_NAME)->error(__VA_ARGS__)
#define MOA_LOG_FATAL_ENGINE(LOGGER_NAME,...) ::Moana::Logger::GetEngineLogger(LOGGER_NAME)->critical(__VA_ARGS__)

#define MOA_LOG_TRACE(LOGGER_NAME,...) ::Moana::Logger::GetClientLogger(LOGGER_NAME)->trace(__VA_ARGS__)
#define MOA_LOG_INFO(LOGGER_NAME,...) ::Moana::Logger::GetClientLogger(LOGGER_NAME)->info(__VA_ARGS__)
#define MOA_LOG_WARN(LOGGER_NAME,...) ::Moana::Logger::GetClientLogger(LOGGER_NAME)->warn(__VA_ARGS__)
#define MOA_LOG_ERROR(LOGGER_NAME,...) ::Moana::Logger::GetClientLogger(LOGGER_NAME)->error(__VA_ARGS__)
#define MOA_LOG_FATAL(LOGGER_NAME,...) ::Moana::Logger::GetClientLogger(LOGGER_NAME)->critical(__VA_ARGS__)