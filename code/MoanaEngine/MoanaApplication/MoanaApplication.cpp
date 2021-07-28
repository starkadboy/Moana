#include "PrecompiledHeaders.h"
#include "MoanaApplication.h"

Moana::MoanaApplication::MoanaApplication() {
	//WindowProperties defaultWindowProperties = WindowProperties();
	//m_pWindow = std::unique_ptr<Window>(Window::Create(defaultWindowProperties));
}

Moana::MoanaApplication::~MoanaApplication() {
}

int
Moana::MoanaApplication::Run() {
	while (true) {
		m_pWindow->OnUpdate();
	}
	return 0;
}