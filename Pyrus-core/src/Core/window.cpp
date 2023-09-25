#include "Window.h"

#include "Platform/Windows/WindowsWindow.h"
#include "Platform/Linux/LinuxWindow.h"

#define PS_PLATFORM_WINDOWS

std::unique_ptr<Window> Window::CreatePlatformWindow()
{
#ifdef PS_PLATFORM_WINDOWS
	return std::make_unique<WindowsWindow>();
#elif PS_PLATFORM_LINUX
	return std::make_unique<LinuxWindow>();
#else
	PS_ASSERT(false, "Invalid Platform!")
#endif 
}




