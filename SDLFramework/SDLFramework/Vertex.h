#pragma once

#include <list>
#include "Edge.h"
#include "IGameObject.h"

class Edge;

class Vertex : public IGameObject
{
public:
	Vertex(int xPos, int yPos);
	int getxPos();
	int getyPos();
	~Vertex();
private:
	//std::list<Edge*> edges;
	int* xPos;
	int* yPos;
};

