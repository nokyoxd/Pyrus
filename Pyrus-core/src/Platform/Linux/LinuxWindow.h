#pragma once

#include "Core/Window.h"

class LinuxWindow : public Window
{
public:
	LinuxWindow();
	~LinuxWindow();

	void SetVSync(bool state) override;
	bool GetVSync() const override;
};

