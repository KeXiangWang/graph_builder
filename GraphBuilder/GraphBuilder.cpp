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
	string fileName = "..\\..\\control.txt";
	controllerParser.readFile(fileName, tables, potentialEdges);
	controllerParser.checkFile(tables, potentialEdges);
	TableParser tableParser;
	Graph graph;
	for (auto table = tables.begin(); table != tables.end(); table++) {
		cout << endl << (*table)->tableName << endl;
		tableParser.parse(*(*table), potentialEdges, graph);
	}
	string vFileName = "graph.v";
	string eFileName = "graph.e";
	graph.outputGraph(vFileName, eFileName);
	return 0;
}
