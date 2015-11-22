#pragma once
#include "AgentBase.h"
class Hero :
	public AgentBase
{
public:
	Hero(const std::string& name, Vertex* spot, SDL_Texture* texture);
	void Move();
	~Hero();
private:
	bool moved = false;
};

