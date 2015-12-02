#include "AgentBase.h"

AgentBase::AgentBase(const std::string& name, Vertex* spot, SDL_Texture* texture)
{
	this->name = std::string(name);
	this->currentPosition = spot;
	IGameObject::SetTexture(texture);
}

void AgentBase::Update(float deltaTime)
{

}

Vertex* AgentBase::GetCurrentPosition()
{
	return this->currentPosition;
};

void AgentBase::Draw()
{
	FWApplication::GetInstance()->SetColor(Color(255, 255, 255, 255));
	FWApplication::GetInstance()->DrawTexture(GetTexture(), *this->currentPosition->GetX(), *this->currentPosition->GetY(), this->imageWidht, this->imageHeight);
}


AgentBase::~AgentBase()
{
	delete this->currentPosition;
}
