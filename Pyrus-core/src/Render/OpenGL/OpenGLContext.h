#pragma once

#include "Render/Context.h"

#include <GLFW/glfw3.h>

class OpenGLContext : public Context
{
public:
	OpenGLContext(GLFWwindow* window) : m_Window(window) { }

	void Init() override;
	void SwapBuffers() override;
private:
	GLFWwindow* m_Window;
};
