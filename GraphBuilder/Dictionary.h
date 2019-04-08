//
// Created by dywkx0612 on 19-4-5.
//

#ifndef GRAPH_BUILDER_DICTIONARY_H
#define GRAPH_BUILDER_DICTIONARY_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>

using std::map;
using std::string;
using std::fstream;

class Dictionary {
public:
    Dictionary() {
        vertexCount = 1;
        labelCount = 1;
        edgeCount = 1;
    };

    ~Dictionary() = default;

    void vertexInsert(const string &detail) {
        if (vertexDictionary.find(detail) == vertexDictionary.end()) {
            vertexDictionary[detail] = vertexCount++;
        }
    };

    void edgeInsert(const string &detail) {
        if (edgeDictionary.find(detail) == edgeDictionary.end()) {
            edgeDictionary[detail] = edgeCount++;
        }
    };

    void labelInsert(const string &detail) {
        if (labelDictionary.find(detail) == labelDictionary.end()) {
            labelDictionary[detail] = labelCount++;
        }
    };

    int getVertexInt(const string &detail) {
        if (vertexDictionary.find(detail) == vertexDictionary.end()) {
            return -1;
        }
        return vertexDictionary[detail];
    };

    int getEdgeInt(const string &detail) {
        if (edgeDictionary.find(detail) == edgeDictionary.end()) {
            return -1;
        }
        return edgeDictionary[detail];
    };

    int getLabelInt(const string &detail) {
        if (labelDictionary.find(detail) == labelDictionary.end()) {
            return -1;
        }
        return labelDictionary[detail];
    };

    void printMap(string &vDictFileName, string &eDictFileName, string &lDictFileName) {
        fstream vFile = fstream(vDictFileName, fstream::out);
        fstream eFile = fstream(eDictFileName, fstream::out);
        fstream lFile = fstream(lDictFileName, fstream::out);
        for (auto &iter :vertexDictionary) {
            vFile << iter.first << "\t" << iter.second << std::endl;
        }
        for (auto &iter :edgeDictionary) {
            eFile << iter.first << "\t" << iter.second << std::endl;
        }
        for (auto &iter :labelDictionary) {
            lFile << iter.first << "\t" << iter.second << std::endl;
        }
    }

private:
    map<string, int> vertexDictionary;
    map<string, int> edgeDictionary;
    map<string, int> labelDictionary;
    int vertexCount;
    int labelCount;
    int edgeCount;
};


#endif //GRAPH_BUILDER_DICTIONARY_H
