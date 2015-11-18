#pragma once

#include "FWApplication.h"
#include "IGameObject.h"

class Game
{
public:
	explicit Game(FWApplication* app);
	void Cycle();
	~Game();
private:
	FWApplication* app;

};

