#pragma once

using std::string;
class Edge
{
public:
	Edge(string &first, string &second) :first(first), second(second){
		name = first + "_to_" + second;
	};
	Edge(string &first, string &second, string &name) :first(first), second(second), name(name) {
	};
	~Edge();
	string first;
	string second;
	string name;
};

