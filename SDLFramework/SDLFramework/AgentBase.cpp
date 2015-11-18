#include "AgentBase.h"



AgentBase::AgentBase(const char* name, Vertex* spot)
{
	this->name = std::string(name);
	this->currentPosition = spot;
}


AgentBase::~AgentBase()
{
	delete this->currentPosition;
}
