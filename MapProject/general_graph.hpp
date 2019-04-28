/**
  *  Worg
  */
#ifndef MAP_GENERAL_GRAPH_H
#define MAP_GENERAL_GRAPH_H

#include "vector.hpp"
#include "base_graph.hpp"

#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

const double INF = 2e9;

class GeneralGraph : public Graph {
private:
    int m_size;
    Vector<std::pair<double, double > > m_nodes;
    Vector<Vector<std::pair<int, double > > > m_adjacency_list;
    Vector<Vector<double > > m_distances;

protected:
    void ResizeGraph(const int size);
    double ComputeDistance(std::pair<double, double >, std::pair<double, double >) override;
    void ComputeDistances();

public:
    GeneralGraph();
    void CreateGraph() override;
    void AddEdge(const int u, const int v);
    double GetDistance(const int u, const int v) override;
};


GeneralGraph::GeneralGraph() {

}


void GeneralGraph::ResizeGraph(const int size) {
    m_size = size;
    m_nodes.Resize(size + 1);
    m_adjacency_list.Resize(size + 1);


    m_distances.Resize(size + 1);
    for (int i = 1; i <= size; i++) {
        m_distances[i].Resize(size + 1);
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            m_distances[i][j] = (i == j) ? 0 : INF;
        }
    }
}


//  Add an undirected edge between {u} and {v}
void GeneralGraph::AddEdge(const int u, const int v) {
    double node_distance = ComputeDistance(m_nodes[u], m_nodes[v]);
    m_adjacency_list[u].PushBack(std::make_pair(v, node_distance));
    m_adjacency_list[v].PushBack(std::make_pair(u, node_distance));
    m_distances[u][v] = m_distances[v][u] = node_distance;
}


//  Compute the distance between two points
double GeneralGraph::ComputeDistance(std::pair<double, double > a, std::pair<double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


void GeneralGraph::CreateGraph() {
    std::cout << "Number of vertices:\n";
    int size; std::cin >> size;
    ResizeGraph(size);

    std::cout << "Give the coordinates of the vertices, each on a separate line:\n";
    for (int i = 1; i <= size; i++) {
        std::cin >> m_nodes[i].first >> m_nodes[i].second;
    }

    std::cout << "Number or edges\n";
    int edge_count; std::cin >> edge_count;

    std::cout << "Give the edges, each on a separate line:\n";
    for (int i = 0; i < edge_count; i++) {
        int u, v; std::cin >> u >> v;
        AddEdge(u, v);
    }

    //  In the end, compute the distance between each pair of nodes.
    ComputeDistances();
}


//  Compute the distance between each pair of nodes using Roy-Floyd's algorithm
void GeneralGraph::ComputeDistances() {
    for (int k = 1; k <= m_size; k++) {
        for (int i = 1; i <= m_size; i++) {
            for (int j = 1; j <= m_size; j++) {
                if (i == k || i == j || k == j) continue;

                m_distances[i][j] = std::min(m_distances[i][j], m_distances[i][k] + m_distances[k][j]);
            }
        }
    }
}


double GeneralGraph::GetDistance(const int u, const int v) {
    return m_distances[u][v];
}


#endif  //  MAP_GENERAL_GRAPH_H
