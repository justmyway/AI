#include "Vertex.h"
#include <iostream>

Vertex::Vertex(int xPos, int yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;

	this->height = 20;
	this->width = 20;
}

int Vertex::GetX()
{
	return this->xPos;
}

int Vertex::GetY()
{
	return this->yPos;
}

void Vertex::Update(float deltaTime)
{
	FWApplication::GetInstance()->SetColor(Color(255, 0 ,0 ,255));
	FWApplication::GetInstance()->DrawRect(this->xPos - this->width/2, this->yPos - this->height / 2, this->width, this->height, true);
}

int Vertex::AmountOfEdges()
{
	return this->edges.size();
}

void Vertex::AddEdge(Edge* edge)
{
	this->edges.push_back(edge);
}

Vertex* Vertex::randomVertex(int counter)
{
	return this->getRandomEdge()->getVertex(this)->randomVertex(counter--);
}

Edge* Vertex::getRandomEdge()
{
	int itraties = (rand() % this->edges.size() - 1)*10;
	while(true)
	{
		for (std::list<Edge *>::iterator it = this->edges.begin(); it != this->edges.end(); ++it)
		{
			if (itraties == 0)
				return *it;
		}
		itraties--;
	}
}

Vertex::~Vertex()
{
}