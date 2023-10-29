#pragma once

#include "Core/Window.h"
#include "Events/Event.h"
#include "Utils/Utils.h"
#include "ImGui/ImGuiLayer.h"

class Application
{
public:
	PS_API Application();
	PS_API ~Application();

	PS_API void Run();
	static void OnEvent(Event& e);

	static Application& Get() { return *m_InstancePtr; };
	std::unique_ptr<Window>& GetWindow() { return m_Window; }

	Application(const Application&) = delete;
	Application(Application&) = delete;
	Application(Application&&) noexcept = delete;
	Application& operator=(Application&) = delete;
	Application& operator=(Application&&) noexcept = delete;
private:
	void OnWindowClose(Event& e) { m_Running = false; }
	void OnWindowResize(Event& e);
private:
	static Application* m_InstancePtr;

	bool m_Running = true;
	bool m_Minimized = false;
	std::unique_ptr<Window> m_Window;
	std::unique_ptr<ImGuiLayer> m_ImGuiLayer;
};
