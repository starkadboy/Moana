#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE AppWindowCloseEvent : public Event {
	public:
		AppWindowCloseEvent() {};

		virtual EventType	GetEventType() const { return EventType::APP_WINDOW_CLOSE; }
		virtual const char* GetName() const { return "AppWindowClose"; }
	};

	class MOA_API_IE AppWindowResizedEvent : public Event {
	public:
		AppWindowResizedEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {};
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		virtual EventType	GetEventType() const { return EventType::APP_WINDOW_RESIZE; }
		virtual const char* GetName() const { return "AppWindowResize"; }
	private:
		unsigned int m_Width{ 0 };
		unsigned int m_Height{ 0 };
	};

	class MOA_API_IE AppWindowFocusEvent : public Event {
	public:
		AppWindowFocusEvent() {};

		virtual EventType	GetEventType() const { return EventType::APP_WINDOW_FOCUS; }
		virtual const char* GetName() const { return "AppWindowFocus"; }
	};

	class MOA_API_IE AppWindowLostFocusEvent : public Event {
	public:
		AppWindowLostFocusEvent() {};

		virtual EventType	GetEventType() const { return EventType::APP_WINDOW_LOST_FOCUS; }
		virtual const char* GetName() const { return "AppWindowLostFocus"; }
	};

	class MOA_API_IE AppWindowMovedEvent : public Event {
	public:
		AppWindowMovedEvent() {};

		virtual EventType	GetEventType() const { return EventType::APP_WINDOW_MOVED; }
		virtual const char* GetName() const { return "AppWindowMoved"; }
	};

}