#pragma once

#include "Core/Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Render/Context.h>

class WindowsWindow : public Window
{
public:
	WindowsWindow();
	virtual ~WindowsWindow();

	unsigned int GetWidth() const override { return m_Data.Width; }
	unsigned int GetHeight() const override { return m_Data.Height; }

	void* GetNativeWindow() const override { return m_Window; }
	void SetEventCallback(const EventCallbackFn& fn) override { m_Data.EventCallback = fn; }

	void OnClear() override;
	void OnUpdate() override;

	void SetVSync(bool state) override;
	bool GetVSync() const override { return m_Data.VSync; }
private:
	GLFWwindow* m_Window = nullptr;
	std::unique_ptr<Context> m_Context;

	struct WindowData
	{
		const char* Title;
		unsigned int Width, Height;
		EventCallbackFn EventCallback;
		bool VSync;

		WindowData() : Title("Pyrus"), Width(1280), Height(720), VSync(false) { }
	};

	bool m_Initialized = false;
	WindowData m_Data;
};
