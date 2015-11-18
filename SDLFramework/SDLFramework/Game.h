#pragma once

#include "FWApplication.h"
#include "Hero.h"
#include "Enemy.h"
#include "Vertex.h"

class Game
{
public:
	explicit Game(FWApplication* app);
	void Cycle();
	~Game();
private:
	void DrawVertex(Vertex* vertex);
	FWApplication* app;

};

