#include "Context.h"

#include "OpenGL/OpenGLContext.h"

struct GLFWwindow;

std::unique_ptr<Context> Context::Create(void* window)
{
	return std::make_unique<OpenGLContext>(static_cast<GLFWwindow*>(window));
}