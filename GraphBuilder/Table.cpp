#include "pch.h"
#include "Table.h"
int Table::tableCount = 0;

Table::~Table() {
}

int Table::find(string &str) {
	for (auto iter = types.begin(); iter != types.end(); iter++) {
		if ((*iter) == str) {
			return (iter - types.begin());
		}
	}
	return -1;
};

void Table::addTypeName(string &typeNameString) {
	types.emplace_back(typeNameString);
};