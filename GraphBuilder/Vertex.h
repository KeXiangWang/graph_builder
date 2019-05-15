#pragma once

#include <string>
using std::string;

class Vertex
{
	friend class Graph;
public:
	Vertex(int name, int label) : name(name), label(label) {};
	~Vertex() = default;
	friend bool operator<(const Vertex& v1, const Vertex& v2)
	{
		return v1.name < v2.name;
	}
//private:
	int name;
	int label;
};

