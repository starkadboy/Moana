#include "PrecompiledHeaders.h"
#include "Logger.h"

std::shared_ptr<Moana::Logger> Moana::Logger::s_pLogger;

const char* Moana::Logger::m_EngineLoggers[(int)eEngineLoggers::LOGGER_NUM] {
	"CORE",
	"ASSERT"
};

const char* Moana::Logger::m_ClientLoggers[(int)eClientLoggers::LOGGER_NUM]{
	"MOANA_APP"
};

void
Moana::Logger::Init() {
	spdlog::set_pattern("%^[%T] %n: %v%$");
	spdlog::set_level(spdlog::level::trace);

	m_pSelfLogger = spdlog::stdout_color_mt(m_ownLoggerName);

	for (int i = 0; i < (int)eEngineLoggers::LOGGER_NUM; i++) {
		m_vSpdEngineLoggers[i] = spdlog::stdout_color_mt(m_EngineLoggers[i]);
	}
	for (int i = 0; i < (int)eClientLoggers::LOGGER_NUM; i++) {
		m_vSpdClientLoggers[i] = spdlog::stdout_color_mt(m_ClientLoggers[i]);
	}

	m_pSelfLogger->info("Logger Module Initialized Succefully");
}

void
Moana::Logger::CreateLoggerModule() {
	if (!s_pLogger) {
		s_pLogger = std::shared_ptr<Logger>(new Logger());
	}
}

std::shared_ptr<spdlog::logger>
Moana::Logger::GetEngineLogger(eEngineLoggers logger) {
	if (!s_pLogger) {
		CreateLoggerModule();
		s_pLogger->m_pSelfLogger->error("CRITICAL: Logger Module was not initialized!");
		return s_pLogger->m_pSelfLogger;
	}
	if ((int)logger < 0 || logger >= eEngineLoggers::LOGGER_NUM) {
		s_pLogger->m_pSelfLogger->error("Logger ID is out of range! The message will be reported using self logger:");
		return s_pLogger->m_pSelfLogger;
	}
	return s_pLogger->m_vSpdEngineLoggers[(int)logger];
}

std::shared_ptr<spdlog::logger>
Moana::Logger::GetClientLogger(eClientLoggers logger) {
	if (!s_pLogger) {
		CreateLoggerModule();
		s_pLogger->m_pSelfLogger->error("CRITICAL: Logger Module was not initialized!");
		return s_pLogger->m_pSelfLogger;
	}
	if ((int)logger < 0 || logger >= eClientLoggers::LOGGER_NUM) {
		s_pLogger->m_pSelfLogger->error("Logger ID is out of range! The message will be reported using self logger:");
		return s_pLogger->m_pSelfLogger;
	}
	return s_pLogger->m_vSpdClientLoggers[(int)logger];
}
