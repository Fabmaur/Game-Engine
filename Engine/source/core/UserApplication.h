#pragma once

namespace core
{
	class UserApplication
	{
	public:
		virtual void Init() = 0;
		virtual void RunMain() = 0;
	};
}