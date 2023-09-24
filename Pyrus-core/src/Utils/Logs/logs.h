#pragma once

#include <format>
#include <fstream>
#include <iostream>

namespace Console {
	inline FILE* Stream = nullptr;
	inline std::ofstream FileStream;

	bool Attach();
	bool Detach();

	bool OpenFile(const char* fileName);
	bool CloseFile();

	template <typename ... Args_t>
	void Log(const std::string_view _Text, const Args_t& ... ArgList)
	{
		if constexpr (sizeof ... (ArgList) > 0)
			std::cout << std::vformat(_Text, std::make_format_args(ArgList...)) << std::endl;
		else
			std::cout << _Text << std::endl;

		if (FileStream.is_open())
			FileStream << _Text << std::endl;
	}
} 