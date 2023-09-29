#include "Pyrus.hpp"

#include <thread>
#include <iostream>
#include <Windows.h>

/*
* We will keep the console for logging
*/
int main(int argc, char** argv)
{
	try
	{
		auto* w = new Application();

		w->Run();

		delete w;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
