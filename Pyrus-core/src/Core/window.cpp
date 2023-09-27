#include "Window.h"

#ifdef PS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#elif PS_PLATFORM_LINUX
	#include "Platform/Linux/LinuxWindow.h"
#endif

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