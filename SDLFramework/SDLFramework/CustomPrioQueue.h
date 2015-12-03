#pragma once

#include <vector>
#include <algorithm>
#include "Vertex.h"

class CustomPrioQueue
{
private:
	std::vector<Vertex*> vertexVect;
	void sortVector();
public:
	CustomPrioQueue();
	~CustomPrioQueue();

	void insert(Vertex* vec);
	bool isPresent(Vertex* vec);
	Vertex* pop();
	bool empty();
};

