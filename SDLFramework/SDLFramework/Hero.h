#pragma once
#include "AgentBase.h"
class Hero :
	public AgentBase
{
public:
	Hero(const char* name, Vertex* spot);
	~Hero();
};

