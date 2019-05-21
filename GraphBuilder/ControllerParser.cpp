#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "ControllerParser.h"

#define STRING_LENGTH 1024
#define DEVIDE_STR "\t"

using std::cout;
using std::endl;
using std::cin;
using std::fstream;


void ControllerParser::readFile(string &fileName, string &directory, vector<Table *> &tables,
                                vector<TypeEdge *> &potentialEdges,
                                Dictionary &dictionary) {

    char buffer[STRING_LENGTH];
    fstream controlFile = fstream(fileName, fstream::in);
    bool parsingEdges = false;
    Table *table;
    if (!controlFile.is_open()) {
        cout << "Error control file!" << endl;
        exit(1);
    }
    while (controlFile.getline(buffer, STRING_LENGTH, '\n')) {
        if (strcmp(buffer, "edges:") == 0) {
            cout << endl << "Start parsing edges." << endl<< endl;
            parsingEdges = true;
            continue;
        }
        if (buffer[strlen(buffer) - 1] == '\r') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if (parsingEdges) {
            char *first = nullptr;
            char *second = nullptr;
            char *next = nullptr;
            first = strtok_r(buffer, DEVIDE_STR, &next);
            cout << first << "\t";
            second = strtok_r(nullptr, DEVIDE_STR, &next);
            cout << second << "\t" << endl;
            string firstName(first);
            string secondName(second);
            potentialEdges.emplace_back(new TypeEdge(firstName, secondName));
        } else {
            char *tablePath = nullptr;
            char *tableName = nullptr;
            char *next = nullptr;
            char *typeName = nullptr;
            tablePath = strtok_r(buffer, DEVIDE_STR, &next);
            if (tablePath == nullptr) {
                continue;
            }
            tableName = strtok_r(nullptr, DEVIDE_STR, &next);
            string tablePathString(directory + "/" + tablePath);
            string tableNameString(tableName);
            table = new Table(tableNameString, tablePathString);
            dictionary.labelInsert(table->types[0]);
            // TODO check
            typeName = strtok_r(nullptr, DEVIDE_STR, &next);
            while (typeName != nullptr) {
                string typeNameString(typeName);
                table->addTypeName(typeNameString);
                // TODO check
                dictionary.labelInsert(typeNameString);
                cout << typeNameString << "\t";
                typeName = strtok_r(nullptr, DEVIDE_STR, &next);
            }
            cout << endl;
            tables.emplace_back(table);
        }
    }
    controlFile.close();
}

void ControllerParser::checkFile(vector<Table *> &tables, vector<TypeEdge *> &potentialEdges) {
    for (auto table :tables) {
        cout << endl << table->tableName << endl;
        for (auto &name : table->types) {
            cout << name << DEVIDE_STR;
        }
    }
    cout << endl;
    for (auto edge :potentialEdges) {
        cout << edge->name << endl;
    }
}


