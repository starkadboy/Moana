#include "PrecompiledHeaders.h"
#include "PCWindow.h"
#include "../Logger.h"
#include "../MoanaAssert.h"

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
