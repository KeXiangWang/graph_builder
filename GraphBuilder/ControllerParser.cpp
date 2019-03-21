#include "pch.h"
#include "ControllerParser.h"
using std::cout;
using std::endl;
using std::cin;
using std::fstream;


ControllerParser::ControllerParser()
{
}


ControllerParser::~ControllerParser()
{
}

void ControllerParser::readFile(vector<Table *> &tables, vector<Edge *> &potentialEdges) {
	string fileName = "..\\..\\control.txt";
	char buffer[STRING_LENGTH];
	fstream controlFile = fstream(fileName, fstream::in);
	bool parsingEdges = false;
	Table *table;
	if (!controlFile.is_open()) {
		cout << "Error control file!" << endl;
		exit(1);
	}

	while (controlFile.getline(buffer, STRING_LENGTH)) {
		if (strcmp(buffer, "edges:") == 0) {
			cout << "Start parsing edges." << endl;
			parsingEdges = true;
			continue;
		}
		if (parsingEdges) {
			char *first = NULL;
			char *second = NULL;
			char *next = NULL;
			first = strtok_s(buffer, DEVIDE_STR, &next);
			cout << first << "\t";
			second = strtok_s(NULL, DEVIDE_STR, &next);
			cout << second << "\t" << endl;
			string firstName(first);
			string secondName(second);
			potentialEdges.emplace_back(new Edge(firstName, secondName));
		}
		else {
			char *tableName = NULL;
			char *next = NULL;
			char *typeName = NULL;
			tableName = strtok_s(buffer, DEVIDE_STR, &next);
			if (tableName == NULL) {
				continue;
			}
			string tableNameString(tableName);
			table = new Table(tableNameString);

			typeName = strtok_s(NULL, DEVIDE_STR, &next);
			while (typeName != NULL) {
				string typeNameString(typeName);
				table->addTypeName(typeNameString);
				cout << typeNameString << "\t";
				typeName = strtok_s(NULL, DEVIDE_STR, &next);
			}
			cout << endl;
			tables.emplace_back(table);
		}
	}
	controlFile.close();
}

void ControllerParser::checkFile(vector<Table *> &tables, vector<Edge *> &potentialEdges) {
	for (auto table = tables.begin(); table != tables.end(); table++) {
		cout << endl << (*table)->tableName << endl;
		for (auto name = (*table)->types.begin(); name != (*table)->types.end(); name++) {
			cout << (*name) << DEVIDE_STR;
		}
	}
	cout << endl;
	for (auto edge = potentialEdges.begin(); edge != potentialEdges.end(); edge++) {
		cout << (*edge)->name << endl;
	}
}


