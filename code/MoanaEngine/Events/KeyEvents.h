#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE CKeyEvent : public CEvent {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
	protected:
		CKeyEvent(int keyCode) : m_KeyCode(keyCode) {};
		int m_KeyCode{ -1 };
	};

	class MOA_API_IE CKeyPressedEvent : public CKeyEvent {
	public:
		CKeyPressedEvent(int keyCode, bool bIsRepeated) : CKeyEvent(keyCode) {};
		inline bool	GetIsRepeated() const { return m_bIsRepeated; }

		static eEventType	GetStaticType() { return eEventType::MOA_KEY_PRESSED; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "KeyPressed"; }
	private:
		bool m_bIsRepeated{ false };
	};

	class MOA_API_IE CKeyReleasedEvent : public CKeyEvent {
	public:
		CKeyReleasedEvent(int keyCode) : CKeyEvent(keyCode) {};

		static eEventType	GetStaticType() { return eEventType::MOA_KEY_RELEASED; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "KeyReleased"; }
	};
}