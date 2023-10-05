#pragma once

#include <memory>

class Context
{
public:
	virtual ~Context() = default;

	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;

	static std::unique_ptr<Context> Create(void* window);
};