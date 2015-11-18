#include "Game.h"

Game::Game(FWApplication* app)
{
	//The draw application
	this->app = app;

	//Graph settings
	int maxVerteces = 15;
	int screenWidth = 700;
	int screenHeight = 500;
	

	Vertex* beginVertex = new Vertex((screenWidth / 2), (screenHeight / 2));

	Game::DrawVertex(beginVertex);

	while(maxVerteces != 1)
	{

		
	}

	IGameObject* hero = new Hero("Holy Lord", beginVertex, this->app->LoadTexture("lemmling_Cartoon_cow.png"));
	IGameObject* haas = new Enemy("Bugs", new Vertex(10,10), this->app->LoadTexture("bunney.png"));

	this->app->AddRenderable(hero);
	this->app->AddRenderable(haas);
}

void Game::Cycle()
{
	
}



Game::~Game()
{
	delete this->app;
}

void Game::DrawVertex(Vertex* vertex)
{
	this->app->SetColor(Color(255, 255, 255, 255));
	this->app->DrawRect(vertex->getxPos(), vertex->getyPos(), 20, 20,true);
}