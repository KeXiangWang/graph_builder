#pragma once

#include <string>

using std::string;

class Edge {
public:
    Edge() = default;
    ~Edge() = default;

};

class TypeEdge:public Edge{
public:
    TypeEdge(string &first, string &second) : first(first), second(second) {
        this->name = first + "_to_" + second;
    };

    ~TypeEdge() = default;

    friend bool operator<(const TypeEdge &v1, const TypeEdge &v2) {
        if (v1.first < v2.first) {
            return true;
        }
        if (v1.first == v2.first && v1.second < v2.second) {
            return true;
        }
        if (v1.first == v2.first && v1.second == v2.second) {
            return v1.name < v2.name;
        }
        return false;
    }
    string first;
    string second;
    string name;
};

class VertexEdge:public Edge{
public:
    VertexEdge(int first, int second, int name) : first(first), second(second), name(name){
    };

    ~VertexEdge() = default;

    friend bool operator<(const VertexEdge &v1, const VertexEdge &v2) {
        if (v1.first < v2.first) {
            return true;
        }
        if (v1.first == v2.first && v1.second < v2.second) {
            return true;
        }
        if (v1.first == v2.first && v1.second == v2.second) {
            return v1.name < v2.name;
        }
        return false;
    }
    int first;
    int second;
    int name;
};
