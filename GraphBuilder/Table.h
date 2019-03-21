#pragma once
using std::string;
using std::vector;

class Table
{
public:
	Table(string tableNameString) :tableName(tableNameString) {
		types.emplace_back("table_" + std::to_string(tableCount++));
	};
	~Table();
	void addTypeName(string &typeNameString);
	int find(string &str);
	string tableName;
	vector<string> types;
private:
	static int tableCount;
};

