#pragma once

#include <string>
#include "Vertex.h"
#include "IGameObject.h"

class AgentBase : public IGameObject
{
public:
	AgentBase(const std::string& name, Vertex* spot);
	void Update(float deltaTime) const;
	~AgentBase();
private:
	std::string name;
	Vertex* currentPosition;
};

