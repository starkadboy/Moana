#include "Moana.h"

class SanboxApp : public Moana::MoanaApplication {
public:
	SanboxApp() {};
	~SanboxApp() {};
};

Moana::MoanaApplication*
CreateMoanaApplication() {
	MOA_LOG_TRACE(Moana::Logger::eClientLoggers::LOGGER_MAIN, "Creating Moana Client Application");
	Moana::MoanaApplication* pSandboxApp = new SanboxApp();
	return pSandboxApp;
};