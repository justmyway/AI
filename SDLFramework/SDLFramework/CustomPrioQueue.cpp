#include "CustomPrioQueue.h"


CustomPrioQueue::CustomPrioQueue()
{
}


CustomPrioQueue::~CustomPrioQueue()
{
}

void CustomPrioQueue::insert(Vertex* vec)
{
	vertexVect.push_back(vec);
}

Vertex* CustomPrioQueue::pop()
{
	Vertex* temp = vertexVect.front();
	vertexVect.erase(vertexVect.begin());
	return temp;
}

bool CustomPrioQueue::isPresent(Vertex* vec)
{
	if (std::find(vertexVect.begin(), vertexVect.end(), vec) != vertexVect.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool CustomPrioQueue::empty()
{
	return vertexVect.empty();
}

void CustomPrioQueue::sortVector()
{
	std::sort(vertexVect.begin(), vertexVect.end());
}
