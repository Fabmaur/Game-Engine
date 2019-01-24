#include "pch.h"
#include "Console.h"

namespace debug
{
	const HANDLE Console::consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::chrono::hours   Console::h;
	std::chrono::minutes Console::m;
	std::chrono::seconds Console::s;
}