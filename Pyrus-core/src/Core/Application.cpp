#include "Application.h"

#include <GLFW/glfw3.h>
#include "Window.h"

Application::Application()
{
    m_Window = Window::Get().Create();
    PS_ASSERT(m_Window != nullptr, "m_Window is a nullptr")

    // Setup all window callbacks
    std::cerr << "Setting up callbacks" << std::endl;
    Window::Get().SetupCallbacks(m_Window);

    // Init renderer etc.
}

Application::~Application()
{
    // Destroy renderer etc.

    Window::Get().Destroy();
}

void Application::Run()
{
    while (!glfwWindowShouldClose(m_Window) && m_Running)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render here

        glfwSwapBuffers(m_Window);

        glfwPollEvents();
    }
}

void Application::OnEvent(EventType eType)
{
    switch (eType)
    {
    case None:
        break;
    case Key:
        break;
    case Mouse:
        break;
    case Cursor:
        break;
    case Resize:
        break;
    case Refresh:
        break;
    case Error:
        break;
    }
}

