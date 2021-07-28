#pragma once

#include "../MoanaApplication/Core.h"

namespace Moana {

	enum class EventType {
		NONE = -1,
		//app events
		MOA_APP_WINDOW_CLOSE,
		MOA_APP_WINDOW_RESIZE,
		MOA_APP_WINDOW_FOCUS,
		MOA_APP_WINDOW_LOST_FOCUS,
		MOA_APP_WINDOW_MOVED,
		MOA_APP_TICK,
		MOA_APP_UPDATE,
		MOA_APP_RENDER,
		//keyboard events
		MOA_KEY_PRESSED,
		MOA_KEY_RELEASED,
		//mouse events
		MOA_MOUSE_BUTTON_PRESSED,
		MOA_MOUSE_BUTTON_RELEASED,
		MOA_MOUSE_MOVED,
		MOA_MOUSE_SCROLLED
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