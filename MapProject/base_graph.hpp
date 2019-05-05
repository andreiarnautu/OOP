/**
  *  Worg
  */
#ifndef MAP_BASE_GRAPH_H
#define MAP_BASE_GRAPH_H

#include <utility>
#include <iostream>

class Graph {
protected:
    virtual double ComputeDistance(std::pair<double, double >, std::pair<double, double >) = 0;
public:
    virtual void AddEdge(const int u, const int v) = 0;
    virtual double GetDistance(const int u, const int v) = 0;
    virtual ~Graph() {};
    virtual void CreateGraph() = 0;
};

#endif  //  MAP_BASE_GRAPH_H
