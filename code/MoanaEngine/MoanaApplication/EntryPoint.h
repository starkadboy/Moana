#pragma once

#include "MoanaApplication.h"
#include "Logger.h"

#ifdef MOA_WINDOWS

extern Moana::CMoanaApplication* CreateMoanaApplication();
	
int main(int argc, char** argv) {
	Moana::CLogger::CreateLoggerModule();
	Moana::CMoanaApplication* pApplication = CreateMoanaApplication();
	pApplication->Run();
	MOA_LOG_TRACE_ENGINE(Moana::CLogger::eEngineLoggers::LOGGER_CORE, "Finished running; deleting Moana Application...");
	delete pApplication;
	return 0;
}

#endif