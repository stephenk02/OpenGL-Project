#include "Application.h"

Application::Application(){
	m_fCurrTime = m_fPrevTime = m_fDeltaTime = 0.0f;
	glfwSetTime(0.0);
}
Application::~Application(){}

Application* m_app;

void WindowResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	m_app->m_iWidth = width;
	m_app->m_iHeight = height;
}

bool Application::startup(){
	if (!glfwInit()){
		return false;
	}

	m_window = glfwCreateWindow(1280, 720, "Untitled Window", nullptr, nullptr);
	if (m_window == nullptr) {
		return false;
	}

	glfwMakeContextCurrent(m_window);
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED){
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}

	int major_version = ogl_GetMajorVersion();
	int minor_version = ogl_GetMinorVersion();
	glfwGetWindowSize(m_window, &m_iWidth, &m_iHeight);

	m_app = this;
	glfwSetWindowSizeCallback(m_window, WindowResize);

	printf("OpenGL V%d.%d successfully loaded.\n", major_version, minor_version);

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	return true;
}
bool Application::shutdown(){
	glfwDestroyWindow(m_window);
	glfwTerminate();
	return true;
}
bool Application::update(){
	if (!glfwWindowShouldClose(m_window)) {
		m_fPrevTime = m_fCurrTime;
		m_fCurrTime = float(glfwGetTime());
		m_fDeltaTime = m_fCurrTime - m_fPrevTime;
	}
	return (!glfwWindowShouldClose(m_window));
}
void Application::draw(){
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}