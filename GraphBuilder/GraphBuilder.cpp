#include "Table.h"
#include "Edge.h"
#include "Graph.h"
#include "ControllerParser.h"
#include "TableParser.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<Table *> tables;
    vector<TypeEdge *> potentialEdges;
    ControllerParser controllerParser;
    Dictionary dictionary = *(new Dictionary());
    string fileName = "../control_pack.txt";
    controllerParser.readFile(fileName, tables, potentialEdges, dictionary);
//	controllerParser.checkFile(tables, potentialEdges);
    TableParser tableParser;
    Graph graph;
    for (auto &table :tables) {
        cout << endl << table->tableName << endl;
        tableParser.parse(*table, potentialEdges, graph, dictionary);
    }
    string vFileName = "graph.v";
    string eFileName = "graph.e";
    graph.outputGraph(vFileName, eFileName, dictionary, true);
    // TODO check
    string vDictFileName = "dictV.txt";
    string eDictFileName = "dictE.txt";
    string lDictFileName = "dictL.txt";
    dictionary.printMap(vDictFileName, eDictFileName, lDictFileName);
    return 0;
}