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
	PS_API void Exit() { this->m_Running = false; };

	void OnEvent(EventType eType = EventType::None);
private:
	bool m_Running = true;
	GLFWwindow* m_Window;
};
