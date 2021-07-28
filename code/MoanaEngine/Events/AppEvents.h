#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE AppWindowCloseEvent : public Event {
	public:
		AppWindowCloseEvent() {};

		static EventType	GetStaticType() { return EventType::MOA_APP_WINDOW_CLOSE; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowClose"; }
	};

	class MOA_API_IE AppWindowResizedEvent : public Event {
	public:
		AppWindowResizedEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {};
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		static EventType	GetStaticType() { return EventType::MOA_APP_WINDOW_RESIZE; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowResize"; }
	private:
		unsigned int m_Width{ 0 };
		unsigned int m_Height{ 0 };
	};

	class MOA_API_IE AppWindowFocusEvent : public Event {
	public:
		AppWindowFocusEvent() {};

		static EventType	GetStaticType() { return EventType::MOA_APP_WINDOW_FOCUS; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowFocus"; }
	};

	class MOA_API_IE AppWindowLostFocusEvent : public Event {
	public:
		AppWindowLostFocusEvent() {};

		static EventType	GetStaticType() { return EventType::MOA_APP_WINDOW_LOST_FOCUS; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowLostFocus"; }
	};

	class MOA_API_IE AppWindowMovedEvent : public Event {
	public:
		AppWindowMovedEvent() {};

		static EventType	GetStaticType() { return EventType::MOA_APP_WINDOW_MOVED; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "AppWindowMoved"; }
	};

}