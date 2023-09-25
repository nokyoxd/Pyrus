#pragma once

#include <string>

enum EventType : int
{
	None = 0,
	WindowClose,
};

struct Event
{
	EventType Type;
};


