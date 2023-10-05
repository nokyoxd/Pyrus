#include "Log.h"

std::shared_ptr<ConsoleLogger> Logger::m_ConsoleLogger;

bool Logger::Init()
{
	m_ConsoleLogger = std::make_shared<ConsoleLogger>();

	// File logging etc. (later)

	return true;
}