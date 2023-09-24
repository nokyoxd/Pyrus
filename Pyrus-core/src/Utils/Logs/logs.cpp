#include "logs.h"

#include <Windows.h>

/*
* Currently unused 
*/
bool Console::Attach()
{
	if (AllocConsole() != TRUE)
		return false;

	AttachConsole(ATTACH_PARENT_PROCESS);

	if (freopen_s(&Stream, "conout$", "w", stdout) != 0)
		return false;

	if (SetConsoleTitle(L"Debug console") != TRUE)
		return false;

	return true;
}

bool Console::Detach()
{
	fclose(Stream);

	if (FreeConsole() != TRUE)
		return false;

	if (HWND consoleWindow = GetConsoleWindow(); consoleWindow != nullptr)
		PostMessage(consoleWindow, WM_CLOSE, 0U, 0L);

	return true;
}

bool Console::OpenFile(const char* fileName)
{
	FileStream.open(fileName, std::ios::out);
	if (!FileStream.is_open())
		return false;

	return true;
}

bool Console::CloseFile()
{
	if (!FileStream.is_open())
		return false;

	FileStream.close();

	return true;
}