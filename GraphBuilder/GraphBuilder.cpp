#include "pch.h"
#include "Table.h"
#include "Edge.h"
#include "Graph.h"
#include "ControllerParser.h"
#include "TableParser.h"
#include <fstream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<Table *> tables;
	vector<Edge *> potentialEdges;
	ControllerParser controllerParser;
	controllerParser.readFile(tables, potentialEdges);
	controllerParser.checkFile(tables, potentialEdges);
	TableParser tableParser;
	Graph graph;
	for (auto table = tables.begin(); table != tables.end(); table++) {
		cout << endl << (*table)->tableName << endl;
		tableParser.parse(*(*table), potentialEdges, graph);
	}
	//std::cout << "Hello World!\n";
	return 0;
}
