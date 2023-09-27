#include "Application.h"

#include <GLFW/glfw3.h>
#include "Utils/Log/Log.h"
#include "Window.h"

Application* Application::m_InstancePtr = nullptr;

Application::Application()
{
    PS_ASSERT(Logger::Init(), "Logger failed to initialize");

    PS_ASSERT(m_InstancePtr == nullptr, "The application is already initialized");
    m_InstancePtr = this;

    m_Window = Window::CreatePlatformWindow();
    PS_ASSERT(m_Window != nullptr, "m_Window is a nullptr")

    PS_CORE_TRACE("Setting up callbacks");
    m_Window->SetEventCallback(OnEvent);

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

    while (m_Running)
    {
        m_Window->OnClear();

        if (!m_Minimized)
        {
            // Render here
        }

        m_Window->OnUpdate();
    }
}

void Application::OnEvent(Event& e)
{
    switch (e.Type)
    {
    case EventType::WindowClose:
        Application::Get().OnWindowClose(e);
    case EventType::WindowResize:
        Application::Get().OnWindowResize(e);
        break;
    }
}

void Application::OnWindowResize(Event& e)
{
    if (m_Window->GetWidth() == 0 || m_Window->GetHeight() == 0)
    {
        m_Minimized = true;
        return;
    }

    m_Minimized = false;
}

