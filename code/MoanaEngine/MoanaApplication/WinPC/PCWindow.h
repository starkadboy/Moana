#pragma once
#include "../Window.h"
#include <GLFW/glfw3.h>

namespace Moana {
	inline static bool s_bGLFWInitialized = false;

	class PCWindow : public Window {
	public:
		PCWindow(const WindowProperties& windowProperties);
		virtual ~PCWindow();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Context.m_Width; };
		inline unsigned int GetHeight() const override { return m_Context.m_Height; };
		bool GetIsVSync() const override;
		void SetVSync(bool bEnable) override;
		void SetEventCallback(const std::function<void(Event&)>& callbackFn);
	private:
		struct WindowContext {
			std::string					 m_Title;
			unsigned int				 m_Width{ 0 };
			unsigned int				 m_Height{ 0 };
			bool						 m_bIsVSync{ false };
			std::function<void(Event&)>  m_callbackFn;
		};

		virtual void Init(const WindowProperties& windowProperties);
		virtual void DeInit();

		GLFWwindow*		m_pWindow{ nullptr };
		WindowContext	m_Context;
	};
}