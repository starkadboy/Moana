#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE CAppWindowCloseEvent : public CEvent {
	public:
		CAppWindowCloseEvent() {};

		static eEventType	GetStaticType() { return eEventType::MOA_APP_WINDOW_CLOSE; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowClose"; }
	};

	class MOA_API_IE CAppWindowResizedEvent : public CEvent {
	public:
		CAppWindowResizedEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {};
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		static eEventType	GetStaticType() { return eEventType::MOA_APP_WINDOW_RESIZE; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowResize"; }
	private:
		unsigned int m_Width{ 0 };
		unsigned int m_Height{ 0 };
	};

	class MOA_API_IE CAppWindowFocusEvent : public CEvent {
	public:
		CAppWindowFocusEvent() {};

		static eEventType	GetStaticType() { return eEventType::MOA_APP_WINDOW_FOCUS; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowFocus"; }
	};

	class MOA_API_IE CAppWindowLostFocusEvent : public CEvent {
	public:
		CAppWindowLostFocusEvent() {};

		static eEventType	GetStaticType() { return eEventType::MOA_APP_WINDOW_LOST_FOCUS; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowLostFocus"; }
	};

	class MOA_API_IE CAppWindowMovedEvent : public CEvent {
	public:
		CAppWindowMovedEvent() {};

		static eEventType	GetStaticType() { return eEventType::MOA_APP_WINDOW_MOVED; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowMoved"; }
	};

}