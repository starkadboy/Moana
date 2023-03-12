#include "PrecompiledHeaders.h"
#include "WinPCWindow.h"
#include "../Logger.h"
#include "../MoanaAssert.h"
#include "../../Events/AppEvents.h"
#include "../../Events/KeyEvents.h"
#include "../../Events/MouseEvents.h"

Moana::CWindow*
Moana::CWindow::Create(const CWindowProperties& windowProperties) {
	return new CWinPCWindow(windowProperties);
}

Moana::CWinPCWindow::CWinPCWindow(const CWindowProperties& windowProperties) {
	Init(windowProperties);
}

void
Moana::CWinPCWindow::Init(const CWindowProperties& windowProperties) {
	m_Context.m_Title = windowProperties.m_Title;
	m_Context.m_Width = windowProperties.m_Width;
	m_Context.m_Height = windowProperties.m_Height;

	MOA_LOG_INFO_ENGINE(CLogger::eEngineLoggers::LOGGER_CORE, "Moana::CWinPCWindow::Init: Creating PC window...");

	if (!s_bGLFWInitialized) {
		int bInitialized = glfwInit();
		moa_assert_msg(bInitialized, "Failed to init GLFW!");
		if (bInitialized) {
			s_bGLFWInitialized = bInitialized;
			m_pWindow = glfwCreateWindow((int)m_Context.m_Width, (int)m_Context.m_Height, m_Context.m_Title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(m_pWindow);
			glfwSetWindowUserPointer(m_pWindow, &m_Context);
			InitCallbacks();
		}
	}
}

Moana::CWinPCWindow::~CWinPCWindow() {
	DeInit();
}

void
Moana::CWinPCWindow::OnUpdate() {
	glfwPollEvents();
	glfwSwapBuffers(m_pWindow);
}

bool
Moana::CWinPCWindow::GetIsVSync() const {
	return m_Context.m_bIsVSync;
}

void
Moana::CWinPCWindow::SetVSync(bool bEnable) {
	glfwSwapInterval(bEnable ? 1 : 0);
	m_Context.m_bIsVSync = bEnable;
}

void
Moana::CWinPCWindow::SetEventCallback(const std::function<void(CEvent&)>& callbackFn) {
	m_Context.m_callbackFn = callbackFn;
}


void
Moana::CWinPCWindow::DeInit() {
	glfwDestroyWindow(m_pWindow);
}

void
Moana::CWinPCWindow::InitCallbacks() {
	glfwSetKeyCallback(m_pWindow, [](GLFWwindow* pWindow, int key, int scancode, int action, int mods) {
		CWindowContext* pWindowContext = (CWindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			switch (action)
			{
			case GLFW_PRESS:
				pWindowContext->m_callbackFn(CKeyPressedEvent(key, 0));
				break;
			case GLFW_REPEAT:
				pWindowContext->m_callbackFn(CKeyPressedEvent(key, 1));
				break;
			case GLFW_RELEASE:
				pWindowContext->m_callbackFn(CKeyReleasedEvent(key));
				break;
			default:
				break;
			}
		}

		}
	);
	glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* pWindow, int button, int action, int mods) {
		CWindowContext* pWindowContext = (CWindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			switch (action)
			{
			case GLFW_PRESS:
				pWindowContext->m_callbackFn(CMouseButtonPressedEvent(button));
				break;
			case GLFW_RELEASE:
				pWindowContext->m_callbackFn(CMouseButtonReleasedEvent(button));
				break;
			default:
				break;
			}
		}

		}
	);
	glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* pWindow, double xpos, double ypos) {
		CWindowContext* pWindowContext = (CWindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			pWindowContext->m_callbackFn(CMouseMovedEvent((float)xpos, (float)ypos));
		}

		}
	);
	glfwSetScrollCallback(m_pWindow, [](GLFWwindow* pWindow, double xoffset, double yoffset) {
		CWindowContext* pWindowContext = (CWindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			pWindowContext->m_callbackFn(CMouseScrolledEvent((float)xoffset, (float)yoffset));
		}

		}
	);
	glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* pWindow) {
		CWindowContext* pWindowContext = (CWindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			pWindowContext->m_callbackFn(CAppWindowCloseEvent());
		}

		}
	);
	glfwSetErrorCallback([](int errorCode, const char* msg) {
		moa_assert_msg(0, msg);
		}
	);
}
