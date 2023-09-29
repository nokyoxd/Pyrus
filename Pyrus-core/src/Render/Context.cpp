#include "Context.h"

void Context::Init()
{
	glfwMakeContextCurrent(m_Window);
}

void Context::SwapBuffers()
{
	glfwSwapBuffers(m_Window);
}
