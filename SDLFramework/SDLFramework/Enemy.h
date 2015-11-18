#pragma once
#include "AgentBase.h"
class Enemy :
	public AgentBase
{
public:
	Enemy(const std::string& name, Vertex* spot, SDL_Texture* texture);
	~Enemy();
};

