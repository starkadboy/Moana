#include "Moana.h"

class CSanboxApp : public Moana::CMoanaApplication {
public:
	CSanboxApp() {};
	~CSanboxApp() {};
};

Moana::CMoanaApplication*
CreateMoanaApplication() {
	MOA_LOG_TRACE(Moana::CLogger::eClientLoggers::LOGGER_MAIN, "Creating Moana Client Application");
	Moana::CMoanaApplication* pSandboxApp = new CSanboxApp();
	return pSandboxApp;
};