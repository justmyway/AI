#include "Hero.h"



Hero::Hero(const std::string& name, Vertex* spot, SDL_Texture* texture) : AgentBase(name, spot, texture)
{
}

void Hero::Move()
{
	if(this->moved)
	{
		this->Draw();
	}else
	{
		this->moved = true;
	}
}

void Hero::OnCollision(IGameObject obj)
{

}

typeobject Hero::getType()
{
	return HERO;
}

void Hero::Draw()
{
	if(this->moved)
	{
		FWApplication::GetInstance()->SetColor(Color(255, 255, 255, 255));
		FWApplication::GetInstance()->DrawTexture(GetTexture(), AgentBase::GetX(), AgentBase::GetY(), 50, 50);
	}
}

Hero::~Hero()
{
	AgentBase::~AgentBase();
}
