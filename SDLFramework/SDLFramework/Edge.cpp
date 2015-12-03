#include "Edge.h"
#include <iostream>


Edge::Edge(Vertex* vertex1, Vertex* vertex2)
{
	this->vertexes.push_back(vertex1);
	this->vertexes.push_back(vertex2);

	vertex1->AddEdge(this);
	vertex2->AddEdge(this);

	int xLength = vertex1->GetX() - vertex2->GetX();
	int yLength = vertex1->GetY() - vertex2->GetY();

	if (xLength < 0)
	// ReSharper disable once CppExpressionStatementsWithoudSideEffects
		xLength * -1;

	if (yLength < 0)
	// ReSharper disable once CppExpressionStatementsWithoudSideEffects
		yLength * -1;

	this->weight = sqrt((xLength * xLength) + (yLength * yLength));
}

void Edge::Update(float deltaTime)
{
	FWApplication::GetInstance()->SetColor(Color(0, 0, 255, 255));
	FWApplication::GetInstance()->DrawLine(this->vertexes.front()->GetX(), this->vertexes.front()->GetY(), this->vertexes.back()->GetX(), this->vertexes.back()->GetY());
}

int Edge::GetWeight()
{
	return this->weight;
}

Vertex * Edge::getVertex(Vertex * vertex)
{
	if (vertex == this->vertexes.front())
	{
		return vertexes.back();
	}
	else
	{
		return vertexes.front();
	}
}

Edge::~Edge()
{
}
