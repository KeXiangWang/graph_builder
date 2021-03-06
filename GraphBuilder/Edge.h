#pragma once

using std::string;
class Edge
{
public:
	Edge(string &first, string &second) :first(first), second(second) {
		name = first + "_to_" + second;
	};
	Edge(string &first, string &second, string &name) :first(first), second(second), name(name) {
	};
	~Edge() {};
	friend bool operator<(const Edge& v1, const Edge& v2)
	{
		if (v1.first < v2.first) {
			return true;
		}
		if (v1.first == v2.first && v1.second < v2.second) {
			return true;
		}
		if (v1.first == v2.first && v1.second == v2.second && v1.name < v2.name) {
			return true;
		}
		return false;
	}
	string first;
	string second;
	string name;

};

