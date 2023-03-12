#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE CMouseMovedEvent : public CEvent {
	public:
		CMouseMovedEvent(float x, float y) : m_X(x), m_Y(y) {};
		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

		static eEventType	GetStaticType() { return eEventType::MOA_MOUSE_MOVED; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "MouseMoved"; }
	private:
		float m_X{ 0.0f };
		float m_Y{ 0.0f };
	};

	class MOA_API_IE CMouseScrolledEvent : public CEvent {
	public:
		CMouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {};
		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		static eEventType	GetStaticType() { return eEventType::MOA_MOUSE_SCROLLED; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "MouseScrolled"; }
	private:
		float m_xOffset{ 0.0f };
		float m_yOffset{ 0.0f };
	};

	class MOA_API_IE CMouseButtonPressedEvent : public CEvent {
	public:
		CMouseButtonPressedEvent(int button) : m_button(button) {};
		inline int GetButton() const { return m_button; }

		static eEventType	GetStaticType() { return eEventType::MOA_MOUSE_BUTTON_PRESSED; }
		virtual eEventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "MouseButtonPressed"; }
	private:
		int m_button{ -1 };
	};

	class MOA_API_IE CMouseButtonReleasedEvent : public CEvent {
	public:
		CMouseButtonReleasedEvent(int button) : m_button(button) {};
		inline int GetButton() const { return m_button; }

		virtual eEventType	GetEventType() const { return eEventType::MOA_MOUSE_BUTTON_RELEASED; }
		virtual const char* GetName() const { return "MouseButtonReleased"; }
	private:
		int m_button{ -1 };
	};
}