#include "Vertex.h"

Vertex::Vertex(int xPos, int yPos) : IGameObject()
{
	this->xPos = &xPos;
	this->yPos = &yPos;

	int height = 20;
	int width = 20;

	IGameObject::SetSize(width, height);
	IGameObject::SetOffset(*(this->xPos - (width / 2)), *(this->yPos - (height / 2)));
	
	IGameObject::SetActive(true);
}

int Vertex::getxPos()
{
	return *this->xPos;
}

int Vertex::getyPos()
{
	return *this->yPos;
}


Vertex::~Vertex()
{
	delete xPos;
	delete yPos;
}