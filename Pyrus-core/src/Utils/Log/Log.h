#pragma once

#include <iostream>
#include <string>

#include <fmt/format.h>

class ConsoleLogger
{
public:
	template <typename... Args_t>
	void Trace(const std::string_view text, Args_t&&... ArgsList)
	{
		LogConsole("[TRACE] " + std::string(text), std::forward<Args_t>(ArgsList)...);
	}

	template <typename ... Args_t>
	void Warn(const std::string_view text, const Args_t&& ... ArgsList)
	{
		LogConsole("[WARN] " + std::string(text), std::forward<Args_t>(ArgsList)...);
	}

	template <typename... Args_t>
	void Error(const std::string_view text, Args_t&&... ArgsList)
	{
		LogConsole("[ERROR] " + std::string(text), std::forward<Args_t>(ArgsList)...);
	}
private:
	template <typename... Args_t>
	void LogConsole(const std::string_view text, Args_t&&... ArgsList)
	{
		if constexpr (sizeof...(ArgsList) > 0)
			std::cout << fmt::format(text, ArgsList...) << std::endl;
		else
			std::cout << text << std::endl;
	}
};

class Logger
{
public:
	static bool Init();

	static std::shared_ptr<ConsoleLogger>& GetConsoleLogger() { return m_ConsoleLogger; }
private:
	static std::shared_ptr<ConsoleLogger> m_ConsoleLogger;
};

#define PS_CORE_TRACE(...)	::Logger::GetConsoleLogger()->Trace(__VA_ARGS__)
#define PS_CORE_WARN(...)	::Logger::GetConsoleLogger()->Warn(__VA_ARGS__)
#define PS_CORE_ERROR(...)	::Logger::GetConsoleLogger()->Error(__VA_ARGS__)