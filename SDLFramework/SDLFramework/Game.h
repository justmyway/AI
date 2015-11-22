#pragma once

#include "FWApplication.h"
#include "Hero.h"
#include "Enemy.h"
#include "Vertex.h"

class Game
{
public:
	explicit Game();
	~Game();
private:
	void AddRenderable(IGameObject* obj);
	void AddRenderable(Vertex* obj);
	void AddRenderable(Edge* obj);
	bool PosibleVertex(const int xPos, const int yPos);
	void moveHero();
	std::vector<Vertex*> vertexes;
	SDL_Texture* LoadTexture(std::string path);
	Hero* hero;
};

