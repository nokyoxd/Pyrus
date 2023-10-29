#pragma once

#include <iostream>
#include <string>

#ifdef PS_PLATFORM_WINDOWS
	#include <Windows.h>
#elif PS_PLATFORM_LINUX
	#include <cstdlib>
#endif

#define PS_API __declspec(dllexport)

#ifdef PS_PLATFORM_WINDOWS
	#define PS_DISPLAY_MESSAGE(msg) MessageBoxA(NULL, msg.c_str(), "Pyrus has crashed!", MB_ICONERROR | MB_OK)
#else
	#define PS_DISPLAY_MESSAGE(msg) ::Logger::GetCoreLogger()->Error("Application has crashed! -> {}", std::string(msg))
#endif

#define PS_ASSERT(con, msg) \
	if (!(con)) \
	{ \
		std::string errorMsg = "\nAssert message: " + std::string(msg); \
		errorMsg += "\nLine: " + std::to_string(__LINE__); \
		errorMsg += "\nFile: " + std::string(__FILE__); \
		PS_DISPLAY_MESSAGE(errorMsg); \
		exit(EXIT_FAILURE); \
	} \
