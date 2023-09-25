#include "Application.h"

#include <GLFW/glfw3.h>
#include "Window.h"

Application* Application::m_InstancePtr = nullptr;

Application::Application()
{
    PS_ASSERT(m_InstancePtr == nullptr, "The application is already initialized");
    m_InstancePtr = this;

    m_Window = Window::CreatePlatformWindow();
    PS_ASSERT(m_Window != nullptr, "m_Window is a nullptr")

    // Setup all window callbacks
    std::cerr << "[PYRUS] Setting up callbacks" << std::endl;
    //Window::Get().SetupCallbacks(m_Window);

    // Init renderer etc.
}

Application::~Application()
{
    // Destroy renderer etc.

    m_InstancePtr = nullptr;
}

void Application::Run()
{
    // Get the GLFWwindow pointer
    auto* window = static_cast<GLFWwindow*>(m_Window->GetNativeWindow());

    while (!glfwWindowShouldClose(window) && m_Running)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render here

        glfwSwapBuffers(window);

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

