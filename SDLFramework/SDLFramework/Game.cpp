#include "Game.h"

Game::Game()
{
	//Graph settings
	int maxVerteces = 15;
	int screenWidth = 700;
	int screenHeight = 500;
	

	Vertex* beginVertex = new Vertex((screenWidth / 2), (screenHeight / 2));

	AddRenderable(beginVertex);

	while(maxVerteces != 1)
	{

		maxVerteces--;
	}

	IGameObject* hero = new Hero("Holy Lord", beginVertex, LoadTexture("lemmling_Cartoon_cow.png"));
	IGameObject* haas = new Enemy("Bugs", new Vertex(10,10), LoadTexture("bunney.png"));

	AddRenderable(hero);
	AddRenderable(haas);
}

void Game::AddRenderable(IGameObject* obj)
{
	FWApplication::GetInstance()->AddRenderable(obj);
}

SDL_Texture* Game::LoadTexture(std::string path)
{
	return FWApplication::GetInstance()->LoadTexture(path);
}

Game::~Game()
{
}

