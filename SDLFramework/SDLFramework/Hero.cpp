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

void Hero::UpdatePosition(Vertex* vertex)
{
	setPosition(vertex);
}

void Hero::Update(float deltaTime)
{
	if (this->moved)
	{
		//todo: move
		//implement a* algorithm
	}
}

void Hero::Draw()
{
	FWApplication::GetInstance()->SetColor(Color(255, 255, 255, 255));
	FWApplication::GetInstance()->DrawTexture(GetTexture(), AgentBase::GetX(), AgentBase::GetY(), 50, 50);
	this->moved = true;
}

Hero::~Hero()
{
	AgentBase::~AgentBase();
}
