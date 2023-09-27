#include "WindowsWindow.h"

#include "Utils/Log/Log.h"

WindowsWindow::WindowsWindow()
{
    Logger::GetCoreLogger()->Info("Initializing GLFW");
    if (!glfwInit())
    {
        Logger::GetCoreLogger()->Error("Initializing GLFW -> Failed!");
        return;
    }
    Logger::GetCoreLogger()->Info("Initialized GLFW | Version {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

    Logger::GetCoreLogger()->Info("Creating Window");
    m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, NULL, NULL);
    if (!m_Window)
    {
        Logger::GetCoreLogger()->Error("Creating Window -> Failed!");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Window);

    Logger::GetCoreLogger()->Info("Initializing GLEW");
    if (glewInit() != GLEW_OK)
    {
        Logger::GetCoreLogger()->Error("Initializing GLEW -> Failed!");
        return;
    }
    Logger::GetCoreLogger()->Info("Initialized GLEW | Version: {}", *glewGetString(GLEW_VERSION));

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
