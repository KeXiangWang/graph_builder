#pragma once
#include "Vertex.h"
#include "Edge.h"

using std::vector;
using std::set;
class Graph
{
	friend class TableParser;
public:
	Graph();
	~Graph();
	void outputGraph();
private:
	set<Vertex> vertexes;
	set<Edge> edges;
	
};

