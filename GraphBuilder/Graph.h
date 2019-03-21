#pragma once
#include "Vertex.h"
#include "Edge.h"

using std::vector;
using std::set;
using std::string;

class Graph
{
	friend class TableParser;
public:
	Graph() {};
	~Graph() {};
	void outputGraph(string &vFile, string &eFile);
private:
	set<Vertex> vertexes;
	set<Edge> edges;
};

