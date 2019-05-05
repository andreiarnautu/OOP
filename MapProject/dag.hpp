/**
  *  Worg
  */
#ifndef MAP_DAG_H
#define MAP_DAG_H

#include "vector.hpp"
#include "base_graph.hpp"

#include <set>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

class DirectedAcyclicGraph : public Graph {
private:
    int m_size;
    Vector<std::pair<double, double > > m_nodes;
    Vector<Vector<std::pair<int, double > > > m_adjacency_list;
    const double INF = 2e9;

protected:
    double ComputeDistance(std::pair<double, double >, std::pair<double, double >) override;
    void ResizeGraph(const int size);
    double RunDijkstra(const int source, const int destination);

public:
    DirectedAcyclicGraph();
    ~DirectedAcyclicGraph();
    void AddEdge(const int u, const int v);
    void CreateGraph();
    double GetDistance(const int u, const int v) override;
};


DirectedAcyclicGraph::DirectedAcyclicGraph() {

}


DirectedAcyclicGraph::~DirectedAcyclicGraph() {

}


double DirectedAcyclicGraph::ComputeDistance(std::pair<double, double > a, std::pair<double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


void DirectedAcyclicGraph::ResizeGraph(const int size) {
    m_size = size;
    m_nodes.Resize(size + 1);
    m_adjacency_list.Resize(size + 1);
}


void DirectedAcyclicGraph::AddEdge(const int u, const int v) {
    double node_distance = ComputeDistance(m_nodes[u], m_nodes[v]);
    m_adjacency_list[u].PushBack(std::make_pair(v, node_distance));
}


void DirectedAcyclicGraph::CreateGraph() {
    std::cout << "Number of vertices:\n";
    int size; std::cin >> size;
    ResizeGraph(size);

    std::cout << "Give the coordinates of the vertices, each on a separate line:\n";
    for (int i = 1; i <= size; i++) {
        std::cin >> m_nodes[i].first >> m_nodes[i].second;
    }

    std::cout << "Number of edges:\n";
    int edge_count; std::cin >> edge_count;

    std::cout << "Give the edges, each on a separate line:\n";
    for (int i = 0; i < edge_count; i++) {
        int u, v; std::cin >> u >> v;
        AddEdge(u, v);
    }
}


double DirectedAcyclicGraph::RunDijkstra(const int source, const int destination) {
    Vector<double > distance(m_size);
    for (int i = 1; i <= m_size; i++) {
        distance[i] = INF;
    }

    std::set<std::pair<double, int > > set; set.insert({0.0, source});

    while (!set.empty()) {
        double current_distance = set.begin()->first;
        int node = set.begin()->second;
        set.erase(set.begin());

        if (distance[node] != INF) continue;
        distance[node] = current_distance;

        if (node == destination) break;

        for (auto it = m_adjacency_list[node].begin(); it != m_adjacency_list[node].end(); it++) {
            if (current_distance + it->second < distance[it->first]) {
                set.insert({current_distance + it->second, it->first});
            }
        }
    }

    return distance[destination];
}


double DirectedAcyclicGraph::GetDistance(const int u, const int v) {
    if (u > m_size || v > m_size) {
        return -1;
    }
    
    double distance = RunDijkstra(u, v);
    return (distance == INF) ? -1 : distance;
}



#endif  //  MAP_DAG_H
