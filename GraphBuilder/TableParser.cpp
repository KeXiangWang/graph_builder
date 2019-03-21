#include "pch.h"
#include "TableParser.h"
using std::fstream;
using std::vector;
using std::string;
using std::to_string;

bool TableParser::parseLine(fstream &file, vector<string> &details)
{
	for (auto iter = details.begin(); iter != details.end(); ) {
		iter = details.erase(iter);
	}
	char buffer[STRING_LENGTH];
	char *next = NULL;
	if (!file.getline(buffer, STRING_LENGTH)) {
		return false;
	}
	char *str = NULL;
	str = strtok_s(buffer, DEVIDE_STR, &next);
	while (str != NULL) {
		string strString(str);
		details.emplace_back(strString);
		str = strtok_s(NULL, DEVIDE_STR, &next);
	}
	return true;
}

void TableParser::openFile(string &fileName, fstream &file) {
	file = fstream(fileName, fstream::in);
	if (!file.is_open()) {
		std::cout << "Error:" << fileName << " can't be opened! " << std::endl;
		exit(1);
	}
	if (!file) {
		std::cout << "Error:" << fileName << " opened wrongly " << std::endl;
		exit(1);
	}
	char buffer[100];
	file.getline(buffer, STRING_LENGTH);
	//std::cout << buffer << std::endl;
}

void TableParser::transfer(Table & table, vector<Edge*>& potentialEdges, vector<EdgeRecord*> &edgeRecords)
{
	for (auto iter = potentialEdges.begin(); iter != potentialEdges.end(); iter++) {
		int a = table.find((*iter)->first);
		int b = table.find((*iter)->second);
		if (a >= 0 && b >= 0) {
			edgeRecords.emplace_back(new EdgeRecord(a, b, (*iter)->name));
		}
	}
}

void TableParser::parse(Table &table, vector<Edge *> &potentialEdges, Graph &graph)
{
	string fileName = "..\\..\\" + table.tableName;
	fstream file;
	openFile(fileName, file);
	vector<string> details;
	vector<EdgeRecord *> edgeRecords;
	transfer(table, potentialEdges, edgeRecords);
	int count = 0;
	while (parseLine(file, details)) {
		details.insert(details.begin(), *table.types.begin() + "_" + to_string(count++));
		for (auto detail = details.begin(); detail != details.end(); detail++) {
			std::cout << *detail << DEVIDE_STR;
			string info = table.types[detail - details.begin()] + "_" + *detail;
			graph.vertexes.insert(*(new Vertex(info)));
		}
		for (auto iter = edgeRecords.begin(); iter != edgeRecords.end(); iter++) {
			int a = (*iter)->first;
			int b = (*iter)->second;
			string first = table.types[a] + "_" + details[a];
			string second = table.types[b] + "_" + details[b];
			graph.edges.insert(*(new Edge(first, second, (*iter)->name)));
		}
		std::cout << std::endl;
	}
}

