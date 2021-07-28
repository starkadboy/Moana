#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/AppEvents.h"

namespace Moana {
	class MOA_API_IE MoanaApplication {
	public:
		MoanaApplication();
		~MoanaApplication();
		int Run();
	private:
		void OnEvent(Event& e);
		bool OnAppCloseEvent(AppWindowCloseEvent& e);

		std::unique_ptr<Window> m_pWindow{ nullptr };
		bool					m_bAppRunning{ true };
	};
}