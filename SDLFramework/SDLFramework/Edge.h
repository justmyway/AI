#pragma once

#include <list>
#include "Vertex.h"
#include "IGameObject.h"

class Vertex;

class Edge : public IGameObject
{
public:
	Edge();
	void AddVertex(Vertex* vertex);
	~Edge();
private:
	std::list<Vertex*> vertexes;
};

