#include "Game.h"

Game::Game(FWApplication* app)
{
	//The draw application
	this->app = app;

	//Graph settings
	int8_t maxVerteces = 15;
	int8_t screenHeight = 500;
	int8_t screenWidth = 700;

	IGameObject* hero = new Hero();
	hero->SetTexture(this->app->LoadTexture("lemmling_Cartoon_cow.png"));

	this->app->AddRenderable(hero);

	/*std::list<AgentBase>* activeAgents = new std::list<AgentBase>();
	AgentBase* hero = new Hero("Holy Lord", new Vertex());
	activeAgents.push_back(hero);*/
}

void Game::Cycle()
{
	
}



Game::~Game()
{
	delete this->app;
}
