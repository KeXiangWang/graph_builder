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

int main(int argc, char **argv) {
    vector<Table *> tables;
    vector<TypeEdge *> potentialEdges;
    ControllerParser controllerParser;
    Dictionary dictionary = *(new Dictionary());
    string fileName = argv[1];
    fstream controlFile = fstream(fileName, fstream::in);
    if (!controlFile) {
        std::cout << fileName << "没有被创建!" << std::endl;
    } else {
        std::cout << fileName << "已经存在!" << std::endl;
    }
//    controllerParser.readFile(fileName, tables, potentialEdges, dictionary);
////	controllerParser.checkFile(tables, potentialEdges);
//    TableParser tableParser;
//    Graph graph;
//    for (auto &table :tables) {
//        cout << endl << table->tableName << endl;
//        tableParser.parse(*table, potentialEdges, graph, dictionary);
//    }
    string vFileName = argv[2] + string("/graph.v");
    string eFileName = argv[2] + string("/graph.e");
//    graph.outputGraph(vFileName, eFileName, dictionary, true);
    // TODO check
    string vDictFileName = argv[3] + string("/dictV.txt");
    string eDictFileName = argv[3] + string("/dictE.txt");
    string lDictFileName = argv[3] + string("/dictL.txt");
    std::cout << vFileName << eFileName << vDictFileName << eDictFileName << lDictFileName << std::endl;
//    dictionary.printMap(vDictFileName, eDictFileName, lDictFileName);
    return 0;
}