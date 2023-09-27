#include "WindowsWindow.h"
#include "Utils/Log/Log.h"

WindowsWindow::WindowsWindow()
{
    PS_CORE_TRACE("Creating window {} ({}, {})", m_Data.Title, m_Data.Width, m_Data.Height);

    if (!m_Initialized)
    {
        PS_CORE_TRACE("Initializing GLFW");
        if (!glfwInit())
        {
            PS_CORE_ERROR("Initializing GLFW -> Failed!");
            return;
        }
        PS_CORE_TRACE("Initialized GLFW | Version: {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
    }

    m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, NULL, NULL);
    if (!m_Window)
    {
        PS_CORE_ERROR("Creating Window -> Failed!");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Window);

    if (!m_Initialized)
    {
        PS_CORE_TRACE("Initializing GLEW");
        if (glewInit() != GLEW_OK)
        {
            PS_CORE_ERROR("Initializing GLEW -> Failed!");
            glfwTerminate();
            return;
        }
        PS_CORE_TRACE("Initialized GLEW | Version: {}.{}.{}", GLEW_VERSION_MAJOR, GLEW_VERSION_MINOR, GLEW_VERSION_MICRO);

        m_Initialized = true;
    }

    glfwSetWindowUserPointer(m_Window, &m_Data);

    // Setup callbacks
    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        Event e;
        e.Type = EventType::WindowClose;

        data.EventCallback(e);
    });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        // We can access the data from the class later
        data.Width = width;
        data.Height = height;

        Event e;
        e.Type = EventType::WindowResize;

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

void WindowsWindow::OnClear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowsWindow::OnUpdate()
{
    glfwPollEvents();

    glfwSwapBuffers(m_Window);
}

void WindowsWindow::SetVSync(bool state)
{
	glfwSwapInterval(state ? 1 : 0);
	m_Data.VSync = state;
}
