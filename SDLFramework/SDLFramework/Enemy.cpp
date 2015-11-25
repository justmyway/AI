#include "Enemy.h"


Enemy::Enemy(const std::string& name, Vertex* spot, SDL_Texture* texture) : AgentBase(name, spot, texture)
{
}

typeobject Enemy::getType()
{
	return HAAS;
}

void Enemy::OnCollision(IGameObject obj)
{
	switch(obj.getType())
	{
	case HERO: this->Relocate();
		break;
	default:;
	}
}

void Enemy::Relocate()
{
	AgentBase::setPosition(AgentBase::getPosition()->randomVertex(50));
}


Enemy::~Enemy()
{
}
