#include "Hero.h"



Hero::Hero(const std::string& name, Vertex* spot, SDL_Texture* texture) : AgentBase(name, spot, texture)
{
}

void Hero::Move()
{
	this->moved = true;
}

Hero::~Hero()
{
	AgentBase::~AgentBase();
}
