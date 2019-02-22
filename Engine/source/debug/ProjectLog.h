#pragma once
#include <memory>
#include "Console.h"

namespace debug {

	class ProjectLog
	{
	public:
		static inline std::unique_ptr<Console>& GetHyperion() {
			auto static hyperionLog = std::make_unique<Console>("Hyperion");
			return hyperionLog;
		};
		static inline std::unique_ptr<Console>& GetGame() {
			auto static gameLog = std::make_unique<Console>("Game");
			return gameLog;
		}
	};
}


#ifdef DEBUG
#define HP_STATUS(...)  ::debug::ProjectLog::GetHyperion()->Status(__VA_ARGS__)
#define HP_SUCCESS(...) ::debug::ProjectLog::GetHyperion()->Success(__VA_ARGS__)
#define HP_WARNING(...) ::debug::ProjectLog::GetHyperion()->Warning(__VA_ARGS__)
#define HP_ERROR(...)   ::debug::ProjectLog::GetHyperion()->Error(__VA_ARGS__)
#define HP_FATAL(...)   ::debug::ProjectLog::GetHyperion()->Fatal(__VA_ARGS__)

#define GAME_STATUS(...)  ::debug::ProjectLog::GetGame()->Status(__VA_ARGS__)
#define GAME_SUCCESS(...) ::debug::ProjectLog::GetGame()->Success(__VA_ARGS__)
#define GAME_WARNING(...) ::debug::ProjectLog::GetGame()->Warning(__VA_ARGS__)
#define GAME_ERROR(...)   ::debug::ProjectLog::GetGame()->Error(__VA_ARGS__)
#define GAME_FATAL(...)   ::debug::ProjectLog::GetGame()->Fatal(__VA_ARGS__)
#else
#define HP_STATUS(...)
#define	HP_SUCCESS(...)
#define	HP_WARNING(...)
#define	HP_ERROR(...)
#define	HP_FATAL(...)

#define GAME_STATUS(...)
#define	GAME_SUCCESS(...)
#define	GAME_WARNING(...)
#define	GAME_ERROR(...)
#define	GAME_FATAL(...)
#endif