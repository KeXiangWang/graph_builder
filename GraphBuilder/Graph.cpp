#include "pch.h"
#include "Graph.h"

using std::string;
using std::fstream;

void Graph::outputGraph(string &vFile, string &eFile)
{
	fstream vfile = fstream(vFile, fstream::out);
	fstream efile = fstream(eFile, fstream::out);
	for (auto iter = vertexes.begin(); iter != vertexes.end(); iter++) {
		vfile << (*iter).name << std::endl;
	}
	for (auto iter = edges.begin(); iter != edges.end(); iter++) {
		efile << (*iter).first << DEVIDE_STR << (*iter).second << DEVIDE_STR << (*iter).name << std::endl;
	}
}
