#pragma once
using std::string;

class Vertex
{
	friend class Graph;
public:
	Vertex(string name) : name(name) {};
	~Vertex();
	friend bool operator<(const Vertex& v1, const Vertex& v2)
	{
		return v1.name < v2.name;
	}
private:
	string name;
};

