/**
  *  Worg
  */
#ifndef MAP_COMPLETE_GRAPH_H
#define MAP_COMPLETE_GRAPH_H

#include <utility>
#include <iostream>

#include "vector.hpp"

class CompleteGraph : public Graph {
private:
    int m_size;
    Vector<std::pair<double, double > > m_nodes;

protected:
    double ComputeDistance(std::pair<double, double >, std::pair<double, double >) override;

public:
    void AddEdge(const int u, const int v) override;
    CompleteGraph();
    ~CompleteGraph();
    double GetDistance(const int u, const int v) override;
    void CreateGraph() override;
};


CompleteGraph::CompleteGraph() {

}


CompleteGraph::~CompleteGraph() {

}


void CompleteGraph::AddEdge(const int u, const int v) {

}


void CompleteGraph::CreateGraph() {
    std::cout << "Number of vertices:\n";
    std::cin >> m_size;
    m_nodes.Resize(m_size + 1);

    std::cout << "Give the coordinates of the vertices, each on a separate line:\n";
    for (int i = 1; i <= static_cast<int >(m_size); i++) {
        std::cin >> m_nodes[i].first >> m_nodes[i].second;
    }
}


//  Compute the distance between two points
double CompleteGraph::ComputeDistance(std::pair<double, double > a, std::pair<double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


double CompleteGraph::GetDistance(const int u, const int v) {
    if (u > m_size || v > m_size) {
        return -1;
    }

    return ComputeDistance(m_nodes[u], m_nodes[v]);
}



#endif  //  MAP_COMPLETE_GRAPH_H
