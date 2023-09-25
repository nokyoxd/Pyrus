#pragma once

#include <string>

#include "Core/Window.h"
#include "Events/Event.h"
#include "Utils/Utils.h"

class Application
{
public:
	PS_API Application();
	PS_API ~Application();

	PS_API void Run();
	void OnEvent(EventType eType = EventType::None);

	static Application& Get() { return *m_InstancePtr; };

	Application(const Application&) = delete;
	Application(Application&) = delete;
	Application(Application&&) noexcept = delete;
	Application& operator=(Application&) = delete;
	Application& operator=(Application&&) noexcept = delete;
private:
	static Application* m_InstancePtr;

	bool m_Running = true;
	std::unique_ptr<Window> m_Window;
};
