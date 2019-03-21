#pragma once
#include "Graph.h"
#include "Table.h"


using std::fstream;
using std::vector;


class EdgeRecord
{
	friend class TableParser;
public:
	EdgeRecord(int first, int second, string name) :first(first), second(second), name(name) {};
private:
	int first;
	int second;
	string name;
};


class TableParser
{
public:
	TableParser() {};
	~TableParser() {};
	void parse(Table &table, vector<Edge *> &potentialEdges, Graph &graph);
	bool parseLine(fstream &file, vector<string> &details);
	void openFile(string &fileName, fstream &file);
	void transfer(Table &table, vector<Edge *> &potentialEdges, vector<EdgeRecord*> &edgeRecords);
};
