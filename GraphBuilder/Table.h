#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

class Table
{
public:
	explicit Table(string &tableNameString, string &tablePathString) :tableName(tableNameString), tablePath(tablePathString) {
		types.emplace_back(tableNameString);
//		types.emplace_back("table_" + std::to_string(tableCount++));
	};
	~Table() = default;
	void addTypeName(string &typeNameString);
	int find(string &str);
	string tablePath;
	string tableName;
	vector<string> types;
private:
	static int tableCount;
};

