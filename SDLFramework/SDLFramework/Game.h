#pragma once
#include "FWApplication.h"

class Game
{
public:
	explicit Game(FWApplication* app);
	void Cycle();
	~Game();
private:
	FWApplication* app;

};

