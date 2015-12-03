#pragma once

#include "FWApplication.h"
#include "Hero.h"
#include "Enemy.h"
#include "Vertex.h"

class Game
{
public:
	explicit Game();
	void moveHero();
	~Game();
private:
	void AddRenderable(IGameObject* obj);
	void AddRenderable(Vertex* obj);
	void AddRenderable(Edge* obj);
	bool PosibleVertex(const int xPos, const int yPos);
	std::vector<Vertex*> vertexes;
	SDL_Texture* LoadTexture(std::string path);
	int Heuristic_cost_estimate(Vertex* start, Vertex* goal);
	Hero* hero;
	Enemy* enemy;
};

