#pragma once

#include <GLFW/glfw3.h>

class Context
{
public:
	Context(GLFWwindow* window) : m_Window(window) { }

	void Init();
	void SwapBuffers();
private:
	GLFWwindow* m_Window;
};
