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

void AgentBase::Draw()
{
	FWApplication::GetInstance()->DrawTexture(GetTexture(), this->currentPosition->GetX(), this->currentPosition->GetY(), this->imageWidht, this->imageHeight);
}


AgentBase::~AgentBase()
{
	delete this->currentPosition;
}
