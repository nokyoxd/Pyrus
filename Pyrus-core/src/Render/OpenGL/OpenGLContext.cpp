#include "OpenGLContext.h"

void OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_Window);
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_Window);
}
