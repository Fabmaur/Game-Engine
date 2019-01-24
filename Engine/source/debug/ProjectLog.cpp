#include "pch.h"
#include "ProjectLog.h"

namespace debug
{
	//Static variable definition
	std::unique_ptr<Console> ProjectLog::hyperionLog;
	std::unique_ptr<Console> ProjectLog::gameLog;
}