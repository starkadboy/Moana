#pragma once

#include "EventSystem.h"

namespace Moana {

	class MOA_API_IE MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_X(x), m_Y(y) {};
		inline int GetX() const { return m_X; }
		inline int GetY() const { return m_Y; }

		static EventType	GetStaticType() { return EventType::MOA_MOUSE_MOVED; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "MouseMoved"; }
	private:
		float m_X{ 0.0f };
		float m_Y{ 0.0f };
	};

	class MOA_API_IE MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {};
		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		static EventType	GetStaticType() { return EventType::MOA_MOUSE_SCROLLED; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "MouseScrolled"; }
	private:
		float m_xOffset{ 0.0f };
		float m_yOffset{ 0.0f };
	};

	class MOA_API_IE MouseButtonPressedEvent : public Event {
	public:
		MouseButtonPressedEvent(int button) : m_button(button) {};
		inline int GetButton() const { return m_button; }

		static EventType	GetStaticType() { return EventType::MOA_MOUSE_BUTTON_PRESSED; }
		virtual EventType	GetEventType() const { return GetStaticType(); }
		virtual const char* GetName() const { return "MouseButtonPressed"; }
	private:
		int m_button{ -1 };
	};

	class MOA_API_IE MouseButtonReleasedEvent : public Event {
	public:
		MouseButtonReleasedEvent(int button) : m_button(button) {};
		inline int GetButton() const { return m_button; }

		virtual EventType	GetEventType() const { return EventType::MOA_MOUSE_BUTTON_RELEASED; }
		virtual const char* GetName() const { return "MouseButtonReleased"; }
	private:
		int m_button{ -1 };
	};
}