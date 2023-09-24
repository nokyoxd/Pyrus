#pragma once

#include <string>

enum EventType : int
{
	None = 0,
	Key,
	Mouse,
	Cursor,
	Resize,
	Refresh,
	Error
};
