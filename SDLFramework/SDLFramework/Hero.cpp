#include "Hero.h"



Hero::Hero(const char* name, Vertex* spot) : AgentBase(name, spot)
{

}


Hero::~Hero()
{
	AgentBase::~AgentBase();
}
