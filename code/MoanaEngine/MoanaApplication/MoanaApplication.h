#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/AppEvents.h"

namespace Moana {
	class MOA_API_IE CMoanaApplication {
	public:
		CMoanaApplication();
		~CMoanaApplication();
		int Run();
	private:
		void OnEvent(CEvent& e);
		bool OnAppCloseEvent(CAppWindowCloseEvent& e);

		std::unique_ptr<CWindow> m_pWindow{ nullptr };
		bool					 m_bAppRunning{ true };
	};
}