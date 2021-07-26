#pragma once

#include "../MoanaApplication/Core.h"

namespace Moana {

	enum class EventType {
		NONE = -1,
		//app events
		APP_WINDOW_CLOSE,
		APP_WINDOW_RESIZE,
		APP_WINDOW_FOCUS,
		APP_WINDOW_LOST_FOCUS,
		APP_WINDOW_MOVED,
		APP_TICK,
		APP_UPDATE,
		APP_RENDER,
		//keyboard events
		KEY_PRESSED,
		KEY_RELEASED,
		//mouse events
		MOUSE_BUTTON_PRESSED,
		MOUSE_BUTTON_RELEASED,
		MOUSE_MOVED,
		MOUSE_SCROLLED
	};

	class MOA_API_IE Event {
	public:
		virtual EventType	GetEventType() const = 0;
		virtual const char* GetName() const = 0;
	private:
		bool m_bHandled;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& e) : m_Event(e) {};
		template<typename T>
		bool Dispatch(std::function<bool(T&)> eventFunction) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_bHandled = eventFunction(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}