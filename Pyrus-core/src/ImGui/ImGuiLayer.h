#pragma once

#include <memory>

class ImGuiLayer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	void Begin();
	void End();

	static std::unique_ptr<ImGuiLayer> Create();
};