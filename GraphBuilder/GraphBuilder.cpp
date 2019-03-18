#include "pch.h"
#include "Table.h"
#include <fstream>

using std::fstream;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
#define DEVIDE_STR "\t"


void readFile(vector<Table> &tables) {
	string fileName = "..\\..\\control.txt";
	char buffer[STRING_LENGTH];
	fstream controlFile = fstream(fileName, fstream::in);
	bool parsingEdges = false;
	Table table;
	if (!controlFile.is_open()) {
		cout << "Error control file!" << endl;
		exit(1);
	}

	while (controlFile.getline(buffer, STRING_LENGTH)) {
		if (strcmp(buffer, "edges:") == 0) {
			cout << "Start parsing edges." << endl;
			parsingEdges = true;
		}
		if (parsingEdges) {
			cout << buffer << endl;
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
			table.addTableName(tableNameString);
			cout << tableNameString << "\t";
			typeName = strtok_s(NULL, DEVIDE_STR, &next);
			while (typeName != NULL) {
				string typeNameString(typeName);
				table.addTypeName(typeNameString);
				cout << typeNameString << "\t";
				typeName = strtok_s(NULL, DEVIDE_STR, &next);
			}
			tables.emplace_back(table);
		}
		//cout << buffer << endl;
	}
	controlFile.close();
}

int main() {
	vector<Table> tables;
	readFile(tables);
	//std::cout << "Hello World!\n";
	return 0;
}
