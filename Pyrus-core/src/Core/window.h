#pragma once

#include <functional>

#include "Utils/Utils.h"
#include "SDK/Macros.h"

#include "Events/Event.h"

class Window
{
public:
	using EventCallbackFn = std::function<void(Event&)>;

	static std::unique_ptr<Window> CreatePlatformWindow();
	virtual ~Window() = default;

	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	virtual void* GetNativeWindow() const = 0;
	virtual void SetEventCallback(const EventCallbackFn& fn) = 0;

	virtual void SetVSync(bool state) = 0;
	virtual bool GetVSync() const = 0;
};