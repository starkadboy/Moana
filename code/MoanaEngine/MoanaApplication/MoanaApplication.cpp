#include "PrecompiledHeaders.h"
#include "MoanaApplication.h"
#include "Logger.h"

Moana::CMoanaApplication::CMoanaApplication() {
	m_bAppRunning = true;
	CWindowProperties defaultWindowProperties = CWindowProperties();
	m_pWindow = std::unique_ptr<CWindow>(CWindow::Create(defaultWindowProperties));
	if (m_pWindow != nullptr) {
		m_pWindow->SetEventCallback(std::bind(&CMoanaApplication::OnEvent, this, std::placeholders::_1));
	}
}

Moana::CMoanaApplication::~CMoanaApplication() {
}

int
Moana::CMoanaApplication::Run() {
	while (m_bAppRunning) {
		if (m_pWindow != nullptr) {
			m_pWindow->OnUpdate();
		}
	}
	return 0;
}

void
Moana::CMoanaApplication::OnEvent(CEvent& e) {
	//MOA_LOG_INFO_ENGINE(CLogger::eEngineLoggers::LOGGER_CORE, "CEvent {0} of type {1} happened!", e.GetName(), e.GetEventType());
	CEventDispatcher eventDispatcher(e);
	eventDispatcher.Dispatch<CAppWindowCloseEvent>(std::bind(&CMoanaApplication::OnAppCloseEvent, this, std::placeholders::_1));
}

bool
Moana::CMoanaApplication::OnAppCloseEvent(CAppWindowCloseEvent& e) {
	m_bAppRunning = false;
	return true;
}
