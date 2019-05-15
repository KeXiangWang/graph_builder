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
//    ../control_pack.txt ../ . .
    string argv_1, argv_2, argv_3, argv_4;
    if (argc == 1) {
        argv_1 = "../control_pack.txt";
        argv_2 = "../";
        argv_3 = ".";
        argv_4 = ".";
    } else {
        argv_1 = argv[1];
        argv_2 = argv[2];
        argv_3 = argv[3];
        argv_4 = argv[4];
    }
    string fileName = argv_1;
    string dataset_directory = string(argv_2);
    string vFileName = argv_3 + string("/graph.v");
    string eFileName = argv_3 + string("/graph.e");
    string vDictFileName = argv_4 + string("/dictV.txt");
    string eDictFileName = argv_4 + string("/dictE.txt");
    string lDictFileName = argv_4 + string("/dictL.txt");
    fstream controlFile = fstream(fileName, fstream::in);
    controllerParser.readFile(fileName, dataset_directory, tables, potentialEdges, dictionary);
//	controllerParser.checkFile(tables, potentialEdges);
    TableParser tableParser;
    Graph graph;
    for (auto &table :tables) {
        cout << endl << table->tableName << endl;
        tableParser.parse(*table, potentialEdges, graph, dictionary);
    }

    graph.outputGraph(vFileName, eFileName, dictionary, true);
    // TODO check
    dictionary.printMap(vDictFileName, eDictFileName, lDictFileName);
    return 0;
}