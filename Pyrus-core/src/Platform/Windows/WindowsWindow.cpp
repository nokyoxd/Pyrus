#include "WindowsWindow.h"

WindowsWindow::WindowsWindow()
{
    std::cerr << "[PYRUS] Initializing GLFW" << std::endl;
    if (!glfwInit())
    {
        std::cerr << "[PYRUS] Initializing GLFW -> Failed!" << std::endl;
        return;
    }

    std::cerr << "[PYRUS] Creating Window" << std::endl;
    m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, NULL, NULL);
    if (!m_Window)
    {
        std::cerr << "[PYRUS] Creating Window -> Failed!" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Data);

    // Setup callbacks
    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        Event e;
        e.Type = EventType::WindowClose;

        data.EventCallback(e);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {

    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
    {

    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
    {

    });

    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
    {

    });

    glfwSetWindowRefreshCallback(m_Window, [](GLFWwindow* window)
    {

    });

    glfwSetErrorCallback(NULL); // Not in use yet
}

WindowsWindow::~WindowsWindow()
{
    glfwDestroyWindow(m_Window);

    glfwTerminate();
}

void WindowsWindow::SetVSync(bool state)
{
	glfwSwapInterval(state ? 1 : 0);
	m_Data.VSync = state;
}
