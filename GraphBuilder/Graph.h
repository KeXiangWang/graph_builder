#pragma once

#include <set>
#include <vector>
#include <fstream>
#include <string>
#include "Vertex.h"
#include "Edge.h"
#include "Dictionary.h"

#define DEVIDE_STR "\t"
using std::vector;
using std::set;
using std::string;


class Graph {
    friend class TableParser;

public:
    Graph() = default;

    ~Graph() = default;

    void outputGraph(string &vFile, string &eFile, Dictionary &dictionary, bool printString) {
        fstream vfile = fstream(vFile, fstream::out);
        fstream efile = fstream(eFile, fstream::out);
        if (printString) {
            for (auto &iter :vertexes) {
                vfile << iter.name << DEVIDE_STR << iter.label << std::endl;
            }
            for (auto &iter:edges) {
                efile << iter.first << DEVIDE_STR << iter.second << DEVIDE_STR << iter.name << std::endl;
            }
        } else {
//            for (auto &iter :vertexes) {
//                vfile << dictionary.getVertexInt(iter.name) << DEVIDE_STR << dictionary.getLabelInt(iter.label)
//                      << std::endl;
//            }
//            for (auto &iter:edges) {
//                efile << dictionary.getVertexInt(iter.first) << DEVIDE_STR << dictionary.getVertexInt(iter.second)
//                      << DEVIDE_STR << dictionary.getEdgeInt(iter.name) << std::endl;
//            }
        }
    };


private:
    set<Vertex> vertexes;
    set<VertexEdge> edges;
};

