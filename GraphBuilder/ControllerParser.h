#pragma once
#include "Table.h"
#include "Edge.h"
using std::vector;

class ControllerParser
{
public:
	ControllerParser();
	~ControllerParser();
	void readFile(vector<Table *> &tables, vector<Edge *> &potentialEdges);
	void checkFile(vector<Table *> &tables, vector<Edge *> &potentialEdges);
};

