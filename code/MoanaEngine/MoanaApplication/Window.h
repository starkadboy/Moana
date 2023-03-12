#pragma once
#include "PrecompiledHeaders.h"
#include "../Events/EventSystem.h"
#include "Core.h"

namespace Moana {
	/*! @brief Struct with basic window properties for CWindow's constructor.*/
	struct CWindowProperties {
		std::string  m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		CWindowProperties(const std::string& title = "Moana Engine",
						 unsigned int width = 1600,
						 unsigned int height = 900)
			: m_Title(title), m_Width(width), m_Height(height)
		{
		}
	};

	/*! @brief Definition of crossplatform CWindow class*/
	class CWindow {
	public:
		virtual ~CWindow() {};

		virtual void			OnUpdate() = 0;
		virtual unsigned int	GetWidth() const = 0;
		virtual unsigned int	GetHeight() const = 0;
		virtual bool			GetIsVSync() const = 0;
		virtual void			SetVSync(bool bEnable) = 0;
		virtual void			SetEventCallback(const std::function<void(CEvent&)>& callbackFn) = 0;

		static CWindow*			Create(const CWindowProperties& windowProperties);
	};
}