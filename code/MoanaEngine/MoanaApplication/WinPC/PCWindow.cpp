#include "PrecompiledHeaders.h"
#include "PCWindow.h"
#include "../Logger.h"
#include "../MoanaAssert.h"
#include "../../Events/AppEvents.h"
#include "../../Events/KeyEvents.h"
#include "../../Events/MouseEvents.h"

Moana::Window*
Moana::Window::Create(const WindowProperties& windowProperties) {
	return new PCWindow(windowProperties);
}

Moana::PCWindow::PCWindow(const WindowProperties& windowProperties) {
	Init(windowProperties);
}

void
Moana::PCWindow::Init(const WindowProperties& windowProperties) {
	m_Context.m_Title = windowProperties.m_Title;
	m_Context.m_Width = windowProperties.m_Width;
	m_Context.m_Height = windowProperties.m_Height;

	MOA_LOG_INFO_ENGINE(Logger::eEngineLoggers::LOGGER_CORE, "Moana::PCWindow::Init: Creating PC window...");

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

Moana::PCWindow::~PCWindow() {
	DeInit();
}

void
Moana::PCWindow::OnUpdate() {
	glfwPollEvents();
	glfwSwapBuffers(m_pWindow);
}

bool
Moana::PCWindow::GetIsVSync() const {
	return m_Context.m_bIsVSync;
}

void
Moana::PCWindow::SetVSync(bool bEnable) {
	glfwSwapInterval(bEnable ? 1 : 0);
	m_Context.m_bIsVSync = bEnable;
}

void
Moana::PCWindow::SetEventCallback(const std::function<void(Event&)>& callbackFn) {
	m_Context.m_callbackFn = callbackFn;
}


void
Moana::PCWindow::DeInit() {
	glfwDestroyWindow(m_pWindow);
}

void
Moana::PCWindow::InitCallbacks() {
	glfwSetKeyCallback(m_pWindow, [](GLFWwindow* pWindow, int key, int scancode, int action, int mods) {
		WindowContext* pWindowContext = (WindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			switch (action)
			{
			case GLFW_PRESS:
				pWindowContext->m_callbackFn(KeyPressedEvent(key, 0));
				break;
			case GLFW_REPEAT:
				pWindowContext->m_callbackFn(KeyPressedEvent(key, 1));
				break;
			case GLFW_RELEASE:
				pWindowContext->m_callbackFn(KeyReleasedEvent(key));
				break;
			default:
				break;
			}
		}

		}
	);
	glfwSetMouseButtonCallback(m_pWindow, [](GLFWwindow* pWindow, int button, int action, int mods) {
		WindowContext* pWindowContext = (WindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			switch (action)
			{
			case GLFW_PRESS:
				pWindowContext->m_callbackFn(MouseButtonPressedEvent(button));
				break;
			case GLFW_RELEASE:
				pWindowContext->m_callbackFn(MouseButtonReleasedEvent(button));
				break;
			default:
				break;
			}
		}

		}
	);
	glfwSetCursorPosCallback(m_pWindow, [](GLFWwindow* pWindow, double xpos, double ypos) {
		WindowContext* pWindowContext = (WindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			pWindowContext->m_callbackFn(MouseMovedEvent((float)xpos, (float)ypos));
		}

		}
	);
	glfwSetScrollCallback(m_pWindow, [](GLFWwindow* pWindow, double xoffset, double yoffset) {
		WindowContext* pWindowContext = (WindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			pWindowContext->m_callbackFn(MouseScrolledEvent((float)xoffset, (float)yoffset));
		}

		}
	);
	glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* pWindow) {
		WindowContext* pWindowContext = (WindowContext*)glfwGetWindowUserPointer(pWindow);

		if (pWindowContext) {
			pWindowContext->m_callbackFn(AppWindowCloseEvent());
		}

		}
	);
	glfwSetErrorCallback([](int errorCode, const char* msg) {
		moa_assert_msg(0, msg);
		}
	);
}
