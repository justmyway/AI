#include "Enemy.h"


Enemy::Enemy(const std::string& name, Vertex* spot, SDL_Texture* texture) : AgentBase(name, spot, texture)
{
}

Enemy::~Enemy()
{
}
