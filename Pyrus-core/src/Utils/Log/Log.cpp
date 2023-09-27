#include "Log.h"

std::shared_ptr<CoreLogger> Logger::m_CoreLogger;

bool Logger::Init()
{
	m_CoreLogger = std::make_shared<CoreLogger>();

	// File logging etc. (later)

	return true;
}