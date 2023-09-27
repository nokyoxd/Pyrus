#pragma once

#include "Core/Window.h"
#include "Events/Event.h"
#include "Utils/Utils.h"

class Application
{
public:
	PS_API Application();
	PS_API ~Application();

	PS_API void Run();
	static void OnEvent(Event& e);

	static Application& Get() { return *m_InstancePtr; };

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
};
