#pragma once
#include "../Window.h"
#include <GLFW/glfw3.h>

namespace Moana {
	inline static bool s_bGLFWInitialized = false;

	/*! @brief Windows OS implementation of the CWindow class*/
	class CWinPCWindow : public CWindow {
	public:
		CWinPCWindow(const CWindowProperties& windowProperties);
		virtual ~CWinPCWindow();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Context.m_Width; };
		inline unsigned int GetHeight() const override { return m_Context.m_Height; };
		bool GetIsVSync() const override;
		void SetVSync(bool bEnable) override;
		/*! @brief Sets a callback method for GLFW events in this window*/
		void SetEventCallback(const std::function<void(CEvent&)>& callbackFn);
	private:
		/*! @brief This window's context (params). Its pointer is set to this window's GLFWwindow*/
		struct CWindowContext {
			std::string					 m_Title;
			unsigned int				 m_Width{ 0 };
			unsigned int				 m_Height{ 0 };
			bool						 m_bIsVSync{ false };
			std::function<void(CEvent&)>  m_callbackFn;
		};

		virtual void Init(const CWindowProperties& windowProperties);
		virtual void DeInit();
		/*! @brief Calls GLFW's set-callback methods for different window events.
		*
		*  Most GLFW's set-callback methods that are called in this method require the following arguments:
		*  @param[in] window The window whose callback to set:
		*		This object's GLFWwindow (m_pWindow) is passed.
		*  @param[in] callback The callback function:
		*		Lambda function is defined per a set-callback method and passed as the callback function.
		*		Each lambda that recieves pointer to GLFWwindow in which an event has happened,
		*		fetches a pointer to its CWindowContext (m_Context, which pointer is initially set to m_pWindow in CWinPCWindow::Init).
		*		Finally, each such lambda calls CWindowContext's member m_callbackFn and passes appropriate Moana defined CEvent type's constructor.
		*		Please note that m_callbackFn is set by Moana Application class.*/
		virtual void InitCallbacks();

		GLFWwindow*		m_pWindow{ nullptr };
		CWindowContext	m_Context;
	};
}