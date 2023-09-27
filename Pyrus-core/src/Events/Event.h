#pragma once

enum EventType : int
{
	None = 0,
	WindowClose,
	WindowResize
};

struct Event
{
	EventType Type;
};


