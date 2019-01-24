#pragma once
#include <windows.h>
#include <iostream>
#include <sstream>
#include <chrono>

/*Console class used to write important information and details
to debugger.*/

namespace debug
{
	class Console
	{
	public:
		Console(const char* name) :name(name) {};
		template<typename ...T>
		void Success(T&& ...args)
		{
			SetTextColour(GREEN);
			PrintTimeName();
			(std::cout << ... << args) << "\n";
			SetTextColour(WHITE);
		}
		template<typename ...T>
		void Status(T&& ...args)
		{
			PrintTimeName();
			(std::cout << ... << args) << "\n";
		}
		template<typename ...T>
		void Warning(T&& ...args)
		{
			SetTextColour(YELLOW);
			PrintTimeName();
			(std::cout << ... << args) << "\n";
			SetTextColour(WHITE);
		}
		template<typename ...T>
		void Error(T&& ...args)
		{
			SetTextColour(RED);
			PrintTimeName();
			(std::cout << ... << args) << "\n";
			SetTextColour(WHITE);
		}
		template<typename ...T>
		void Fatal(T&& ...args)
		{

			SetTextColour(LIGHTRED);
			PrintTimeName();
			(std::cout << ... << args) << "\n";
			SetTextColour(WHITE);

		}


	private:
		void PrintTimeName()
		{
			std::cout << GetTime() << "[" << name << "]";
		}
		std::string GetTime()
		{
			using namespace std;
			using namespace std::chrono;
			typedef duration<int, ratio_multiply<hours::period, ratio<24> >::type> days;
			system_clock::time_point now = system_clock::now();
			system_clock::duration tp = now.time_since_epoch();
			days d = duration_cast<days>(tp);
			tp -= d;
			h = duration_cast<hours>(tp);
			tp -= h;
			m = duration_cast<minutes>(tp);
			tp -= m;
			s = duration_cast<seconds>(tp);
			tp -= s;

			stringstream ss;
			ss << "[" << h.count() << ":"
				<< m.count() << ":"
				<< s.count() << "]";
			return ss.str();
		}
		template<typename ...T>
		void SetTextColour(const int& colour)
		{
			SetConsoleTextAttribute(consoleHandle, colour);
		}

	private:
		static const HANDLE consoleHandle;
		std::string name;

		//Used to calculate time
		static std::chrono::hours h;
		static std::chrono::minutes m;
		static std::chrono::seconds s;

		//Keycodes for console text colour
		static constexpr int  BLACK = 0;
		static constexpr int  BLUE = 1;
		static constexpr int  GREEN = 2;
		static constexpr int  CYAN = 3;
		static constexpr int  RED = 4;
		static constexpr int  MAGENTA = 5;
		static constexpr int  BROWN = 6;
		static constexpr int  LIGHTGRAY = 7;
		static constexpr int  DARKGRAY = 8;
		static constexpr int  LIGHTBLUE = 9;
		static constexpr int  LIGHTGREEN = 10;
		static constexpr int  LIGHTCYAN = 11;
		static constexpr int  LIGHTRED = 12;
		static constexpr int  LIGHTMAGENTA = 13;
		static constexpr int  YELLOW = 14;
		static constexpr int  WHITE = 15;

	};

	//Static variable definitions
}