#pragma once
#include <string>
#include <iostream>

#ifdef PS_PLATFORM_WINDOWS
	#include <Windows.h>
#elif PS_PLATFORM_LINUX
	#include <cstdlib>
#endif

#define PS_API __declspec(dllexport)

#define PS_ASSERT(con, msg) \
	if (!(con)) \
	{ \
		std::string errorMsg = std::string(msg); \
		errorMsg += "\nLine: " + std::to_string(__LINE__); \
		errorMsg += " | File: " + std::string(__FILE__); \
		Logger::GetCoreLogger()->Error("Application has crashed! -> {}", std::string(errorMsg)); \
		exit(EXIT_FAILURE); \
	} \
