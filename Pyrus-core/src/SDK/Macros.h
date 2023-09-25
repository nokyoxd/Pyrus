#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

#define PS_API __declspec(dllexport)

#define PS_ASSERT(con, msg) \
	do { \
		if (!(con)) \
		{ \
			std::string errorMsg = "\nAssert message: " + std::string(msg); \
			errorMsg += "\nLine: " + std::to_string(__LINE__); \
			errorMsg += "\nFile: " + std::string(__FILE__); \
			MessageBoxA(NULL, errorMsg.c_str(), "Pyrus has crashed!", MB_ICONERROR | MB_OK); \
			exit(EXIT_FAILURE); \
		} \
	} while(0); \

#define ASSERT_FN(func, exp, func_name) AssertFunc(func, exp, func_name);

template <typename fn, typename T>
void AssertFunc(fn* func, T exp, const std::string& fn_name)
{
	T result = (*func)();

	std::cout << "Status | " << "Calling " << fn_name << " at -> " << "0x" << func << std::endl;

	if (result != exp)
		std::cout << "Error | "
		<< fn_name << " call failed! (Expected: "
		<< exp << ", Returned: " << result << ")"
		<< std::endl;
}
