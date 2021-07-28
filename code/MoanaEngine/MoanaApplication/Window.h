#pragma once
#include "PrecompiledHeaders.h"
#include "../Events/EventSystem.h"
#include "Core.h"

namespace Moana {
	struct WindowProperties {
		std::string  m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		WindowProperties(const std::string& title = "Moana Engine",
						 unsigned int width = 1600,
						 unsigned int height = 900)
			: m_Title(title), m_Width(width), m_Height(height)
		{
		}
	};

	class Window {
	public:
		virtual ~Window() {};

		virtual void			OnUpdate() = 0;
		virtual unsigned int	GetWidth() const = 0;
		virtual unsigned int	GetHeight() const = 0;
		virtual bool			GetIsVSync() const = 0;
		virtual void			SetVSync(bool bEnable) = 0;
		virtual void			SetEventCallback(const std::function<void(Event&)>& callbackFn) = 0;

		static Window*			Create(const WindowProperties& windowProperties);
	};
}