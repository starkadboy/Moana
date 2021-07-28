#include "PrecompiledHeaders.h"
#include "MoanaApplication.h"
#include "Logger.h"

Moana::MoanaApplication::MoanaApplication() {
	m_bAppRunning = true;
	WindowProperties defaultWindowProperties = WindowProperties();
	m_pWindow = std::unique_ptr<Window>(Window::Create(defaultWindowProperties));
	if (m_pWindow != nullptr) {
		m_pWindow->SetEventCallback(std::bind(&MoanaApplication::OnEvent, this, std::placeholders::_1));
	}
}

Moana::MoanaApplication::~MoanaApplication() {
}

int
Moana::MoanaApplication::Run() {
	while (m_bAppRunning) {
		if (m_pWindow != nullptr) {
			m_pWindow->OnUpdate();
		}
	}
	return 0;
}

void
Moana::MoanaApplication::OnEvent(Event& e) {
	//MOA_LOG_INFO_ENGINE(Logger::eEngineLoggers::LOGGER_CORE, "Event {0} of type {1} happened!", e.GetName(), e.GetEventType());
	EventDispatcher eventDispatcher(e);
	eventDispatcher.Dispatch<AppWindowCloseEvent>(std::bind(&MoanaApplication::OnAppCloseEvent, this, std::placeholders::_1));
}

bool
Moana::MoanaApplication::OnAppCloseEvent(AppWindowCloseEvent& e) {
	m_bAppRunning = false;
	return true;
}
