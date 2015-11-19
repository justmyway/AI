#pragma once

#include <list>
#include "Vertex.h"
#include "IGameObject.h"

class Vertex;

class Edge : public virtual IGameObject
{
public:
	Edge();
	void AddVertex(Vertex* vertex);
	void Update(float deltaTime) override;
	~Edge();
private:
	std::list<Vertex*> vertexes;
};

