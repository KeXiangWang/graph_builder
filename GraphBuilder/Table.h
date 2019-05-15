#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

class Table
{
public:
	explicit Table(string &tableNameString) :tableName(tableNameString) {
		types.emplace_back("table_" + std::to_string(tableCount++));
	};
	~Table() = default;
	void addTypeName(string &typeNameString);
	int find(string &str);
	string tableName;
	vector<string> types;
private:
	static int tableCount;
};

