#pragma once

#include "Core/Window.h"

#include <GLFW/glfw3.h>

struct WindowData
{
	const char* Title;
	int Width;
	int Height;
	bool Minimized;
	bool VSync;

	WindowData() : Title("Pyrus"), Width(1280), Height(720), Minimized(false), VSync(false) { }
};

class WindowsWindow : public Window
{
public:
	WindowsWindow();
	virtual ~WindowsWindow();

	void* GetNativeWindow() const override;

	void SetEventCallbacks(void* fn) override;

	void SetVSync(bool state) override;
	bool GetVSync() const override;
private:
	GLFWwindow* m_Window = nullptr;
	WindowData m_Data;
};
