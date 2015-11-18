#include "Edge.h"
#include <iostream>


Edge::Edge()
{
	this->vertexes = std::list<Vertex*>();
}

void Edge::AddVertex(Vertex* vertex)
{
	if(this->vertexes.size() < 2)
	{
		this->vertexes.push_back(vertex);
	}
	else
	{
		std::cout << "ERROR: a 3rth Vertex on a Edge?";
	}
}


Edge::~Edge()
{
}
