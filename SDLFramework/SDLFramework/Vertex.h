#pragma once

#include <list>
#include "Edge.h"
#include "IGameObject.h"

class Edge;

class Vertex : public virtual IGameObject
{
public:
	Vertex(int xPos, int yPos);
	virtual void Update(float deltaTime) override;
	int AmountOfEdges();
	void AddEdge(Edge* edge);
	Vertex* randomVertex(int counter);
	Edge* getRandomEdge();
	int GetX();
	int GetY();
	~Vertex();
private:
	std::list<Edge*> edges;
	int xPos;
	int yPos;
	int height;
	int width;
};

