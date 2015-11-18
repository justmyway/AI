#include "Hero.h"



Hero::Hero(const std::string& name, Vertex* spot, SDL_Texture* texture) : AgentBase(name, spot)
{
	IGameObject::SetTexture(texture);
}


Hero::~Hero()
{
	AgentBase::~AgentBase();
}
