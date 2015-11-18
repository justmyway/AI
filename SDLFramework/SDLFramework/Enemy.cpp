#include "Enemy.h"


Enemy::Enemy(const std::string& name, Vertex* spot, SDL_Texture* texture) : AgentBase(name, spot)
{
	IGameObject::SetTexture(texture);
}

Enemy::~Enemy()
{
}
