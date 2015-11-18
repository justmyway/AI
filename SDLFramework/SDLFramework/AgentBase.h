#pragma once

#include <string>
#include "Vertex.h"
#include "IGameObject.h"

class AgentBase : public IGameObject
{
public:
	AgentBase(const char* name, Vertex* spot);
	~AgentBase();
private:
	std::string name;
	Vertex* currentPosition;
};

