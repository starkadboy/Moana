#pragma once

#include "Core.h"
#include "Window.h"

namespace Moana {
	class MOA_API_IE MoanaApplication {
	public:
		MoanaApplication();
		~MoanaApplication();
		int Run();
	private:
		std::unique_ptr<Window> m_pWindow{ nullptr };
	};
}