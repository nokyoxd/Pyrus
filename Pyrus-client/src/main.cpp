#include "Pyrus.hpp"

#include <iostream>
#include <Windows.h>

/*
* We will keep the console for logging
*/
int main(int argc, char** argv)
{
	try
	{
		auto* app = new Application();

		app->Run();

		delete app;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
