#pragma once
#include "Table.h"
#include "Edge.h"
#include "Dictionary.h"
using std::vector;

class ControllerParser
{
public:
	ControllerParser() = default;
	~ControllerParser() = default;
	void readFile(string &fileName, vector<Table *> &tables, vector<TypeEdge *> &potentialEdges, Dictionary &dictionary);
	void checkFile(vector<Table *> &tables, vector<TypeEdge *> &potentialEdges);
};

