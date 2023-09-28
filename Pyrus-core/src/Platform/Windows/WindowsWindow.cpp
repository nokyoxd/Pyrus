#include "WindowsWindow.h"
#include "Utils/Log/Log.h"

static void GLFWErrorCallback(int error, const char* description)
{
    PS_CORE_ERROR("GLFW Error -> {}, {}", error, description);
}

WindowsWindow::WindowsWindow()
{
    PS_CORE_TRACE("Creating window -> {} ({}, {})", m_Data.Title, m_Data.Width, m_Data.Height);

    if (!m_Initialized)
    {
        PS_ASSERT(glfwInit(), "Failed to initialize GLFW!");
        glfwSetErrorCallback(GLFWErrorCallback);
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
        PS_ASSERT(!glewInit(), "Failed to initialize GLEW!");

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
