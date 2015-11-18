#include "Game.h"



Game::Game(FWApplication* app)
{
	this->app = app;
}

void Game::Cycle()
{
	
}



Game::~Game()
{
	delete this->app;
}
