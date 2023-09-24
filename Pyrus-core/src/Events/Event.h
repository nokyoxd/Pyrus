#pragma once

#include <string>s

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
