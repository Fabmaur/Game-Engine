#pragma once
#include "core/UserApplication.h"

/*The user defined game which inherits from user application.
Holds a list of layers which the engine iterates through
and processes.*/

class Game : public core::UserApplication
{
public:
	Game();
};