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


void ControllerParser::readFile(string &fileName, vector<Table *> &tables, vector<TypeEdge *> &potentialEdges,
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
            cout << "Start parsing edges." << endl;
            parsingEdges = true;
            continue;
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
            char *tableName = nullptr;
            char *next = nullptr;
            char *typeName = nullptr;
            tableName = strtok_r(buffer, DEVIDE_STR, &next);
            if (tableName == nullptr) {
                continue;
            }
            string tableNameString(tableName);
            table = new Table(tableNameString);
            // TODO check
            dictionary.labelInsert(table->types[0]);
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


