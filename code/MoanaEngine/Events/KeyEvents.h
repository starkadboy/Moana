#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {};
		int m_KeyCode{ -1 };
	};

	class MOA_API_IE KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, bool bIsRepeated) : KeyEvent(keyCode) {};
		inline bool	GetIsRepeated() const { return m_bIsRepeated; }

		static EventType	GetStaticType() { return EventType::MOA_KEY_PRESSED; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "KeyPressed"; }
	private:
		bool m_bIsRepeated{ false };
	};

	class MOA_API_IE KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {};

		static EventType	GetStaticType() { return EventType::MOA_KEY_RELEASED; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "KeyReleased"; }
	};
}