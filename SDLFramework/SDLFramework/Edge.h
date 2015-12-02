#pragma once

#include <list>
#include "Vertex.h"
#include "IGameObject.h"

class Vertex;

class Edge : public virtual IGameObject
{
public:
	Edge(Vertex* vertex1, Vertex* vertex2);
	void Update(float deltaTime) override;
	int GetWeight();
	Vertex* getVertex(Vertex* vertex);
	~Edge();
private:
	std::list<Vertex*> vertexes;
	int weight;
};

