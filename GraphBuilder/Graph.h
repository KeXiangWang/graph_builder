#pragma once
#include "Vertex.h"

using std::vector;
class Graph
{
public:
	Graph();
	~Graph();
private:
	vector<Vertex *> vertexes;

};

