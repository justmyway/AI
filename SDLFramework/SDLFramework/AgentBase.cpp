#include "AgentBase.h"

AgentBase::AgentBase(const std::string& name, Vertex* spot)
{
	this->name = std::string(name);
	this->currentPosition = spot;
}

void AgentBase::Update(float deltaTime) const
{
}


AgentBase::~AgentBase()
{
	delete this->currentPosition;
}
