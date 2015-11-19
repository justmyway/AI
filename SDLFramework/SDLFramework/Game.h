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
	SDL_Texture* LoadTexture(std::string path);

};

