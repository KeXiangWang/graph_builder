cmake_minimum_required(VERSION 3.13)
project(graph_builder)

set(CMAKE_CXX_STANDARD 14)

include_directories(GraphBuilder)

add_executable(graph_builder
        GraphBuilder/ControllerParser.cpp
        GraphBuilder/ControllerParser.h
        GraphBuilder/Edge.h
        GraphBuilder/Graph.h
        GraphBuilder/GraphBuilder.cpp
        GraphBuilder/Table.cpp
        GraphBuilder/Table.h
        GraphBuilder/TableParser.cpp
        GraphBuilder/TableParser.h
        GraphBuilder/Vertex.h
        GraphBuilder/Dictionary.h)
