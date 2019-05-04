/**
  *  Worg
  */
#ifndef MAP_LINE_GRAPH_H
#define MAP_LINE_GRAPH_H

#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

class LineGraph : public Graph {
private:
    int m_size;
    Vector<std::pair<double, double > > m_nodes;
    Vector<int > m_fictive_index;
    Vector<double > m_partial_sums;


protected:
    double ComputeDistance(std::pair<double, double >, std::pair<double, double >) override;
    void ResizeGraph(const int size);

public:
    LineGraph();
    ~LineGraph();
    void CreateGraph() override;
    double GetDistance(const int u, const int v) override;
};


LineGraph::LineGraph() {

}


LineGraph::~LineGraph() {

}


double LineGraph::ComputeDistance(std::pair<double, double > a, std::pair<double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


void LineGraph::ResizeGraph(const int size) {
    m_size = size;
    m_nodes.Resize(size + 1);
    m_fictive_index.Resize(size + 1);
    m_partial_sums.Resize(size + 1);
}


void LineGraph::CreateGraph() {
    std::cout << "Number of vertices:\n";
    int size; std::cin >> size;
    ResizeGraph(size);


    std::cout << "Give the coordinates of the vertices, each on a separate line:\n";
    for (int i = 1; i <= size; i++) {
        std::cin >> m_nodes[i].first >> m_nodes[i].second;
    }

    int previous_node = -1;

    std::cout << "Enter the indexes of the vertices in the order they appear on the chain, each on a separate line:\n";

    for (int i = 0; i < size; i++) {
        int node; std::cin >> node;

        m_fictive_index[node] = i;

        if (previous_node != -1) {
            m_partial_sums[i] = m_partial_sums[i - 1] + GetDistance(previous_node, node);
        } else {
            m_partial_sums[i] = 0;
        }
    }
}


double LineGraph::GetDistance(const int u, const int v) {
    int a = m_fictive_index[u], b = m_fictive_index[v];

    if (a > b) {
        std::swap(a, b);
    }

    return m_partial_sums[b] - m_partial_sums[a];
}




#endif  //  MAP_LINE_GRAPH_H
