#include "Vertex.h"

Vertex::Vertex(int xPos, int yPos)
{
	this->xPos = &xPos;
	this->yPos = &yPos;

	int height = 20;
	int width = 20;

	IGameObject::SetSize(width, height);
	IGameObject::SetOffset(*(this->xPos - (width / 2)), *(this->yPos - (height / 2)));
	
	IGameObject::SetActive(true);
}

int Vertex::GetX()
{
	return *this->xPos;
}

int Vertex::GetY()
{
	return *this->yPos;
}

void Vertex::Update(float deltaTime)
{
}

Vertex::~Vertex()
{
	delete xPos;
	delete yPos;
}