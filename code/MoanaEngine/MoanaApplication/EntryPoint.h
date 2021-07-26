#pragma once

#include "MoanaApplication.h"
#include "Logger.h"

#ifdef MOA_WINDOWS

extern Moana::MoanaApplication* CreateMoanaApplication();
	
int main(int argc, char** argv) {
	Moana::Logger::CreateLoggerModule();
	Moana::MoanaApplication* pApplication = CreateMoanaApplication();
	pApplication->Run();
	MOA_LOG_TRACE_ENGINE(Moana::Logger::eEngineLoggers::LOGGER_CORE, "Finished running; deleting Moana Application...");
	delete pApplication;
	return 0;
}

#endif