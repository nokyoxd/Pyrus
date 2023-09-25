#pragma once

#include <functional>

#include "Utils/Utils.h"
#include "SDK/Macros.h"

class Window
{
public:
	static std::unique_ptr<Window> CreatePlatformWindow();
	virtual ~Window() = default;

	virtual void* GetNativeWindow() const = 0;

	virtual void SetEventCallbacks(void* fn) = 0;

	virtual void SetVSync(bool state) = 0;
	virtual bool GetVSync() const = 0;
};