#pragma once

#include "Utils/Utils.h"
#include "Utils/Macros.h"

struct GLFWwindow;

struct WindowData
{
	const char* Title;
	int Width;
	int Height;
	bool Minimized;

	// Initialize with default
	WindowData() : Title("Pyrus"), Width(1280), Height(720), Minimized(false) { }
};

class Window : public Singleton<Window>
{
public:
	GLFWwindow* Create();
	void Destroy();

	void SetupCallbacks(GLFWwindow* window);

	static void onKeyEvent(GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mode);
	static void onMouseButtonEvent(GLFWwindow* window, int32_t button, int32_t action, int32_t mods);
	static void onCursorPosition(GLFWwindow* window, double x, double y);
	static void onResized(GLFWwindow* window, int32_t width, int32_t height);
	static void onRefreshWindow(GLFWwindow* window);

	WindowData GetWindowData() { return this->m_Data; }
private:
	WindowData m_Data;
};