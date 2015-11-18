#pragma once
#include "AgentBase.h"
class Enemy :
	public AgentBase
{
public:
	Enemy(const char* name, Vertex* spot);
	~Enemy();
};

