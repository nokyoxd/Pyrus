#include "Window.h"

#include <Windows.h>

#include <GLFW/glfw3.h>

GLFWwindow* Window::Create()
{
    GLFWwindow* window;

    std::cerr << "[PYRUS] Initializing GLFW" << std::endl;
    if (!glfwInit())
    {
        std::cerr << "[PYRUS] Initializing GLFW -> Failed!" << std::endl;
        return nullptr;
    }

    std::cerr << "[PYRUS] Creating Window" << std::endl;
    window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, NULL, NULL);
    if (!window)
    {
        std::cerr << "[PYRUS] Creating Window -> Failed!" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    return window;
}

void Window::Destroy()
{
    glfwTerminate();
}

void Window::SetupCallbacks(GLFWwindow* window)
{
    glfwSetKeyCallback(window, onKeyEvent);
    glfwSetMouseButtonCallback(window, onMouseButtonEvent);
    glfwSetCursorPosCallback(window, onCursorPosition);
    glfwSetFramebufferSizeCallback(window, onResized);

    glfwSwapInterval(1);

    glfwSetWindowRefreshCallback(window, onRefreshWindow);
    glfwSetErrorCallback(NULL); // Not used yet
}

void Window::onKeyEvent(GLFWwindow*, int32_t key, int32_t scancode, int32_t action, int32_t mode) 
{

}

void Window::onMouseButtonEvent(GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
{

}

void Window::onCursorPosition(GLFWwindow* window, double x, double y)
{

}

void Window::onResized(GLFWwindow* window, int32_t width, int32_t height)
{

}

void Window::onRefreshWindow(GLFWwindow* window)
{

}
