/**
  *  Worg
  */
#ifndef MAP_TREE_H
#define MAP_TREE_H

#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

#include "vector.hpp"
#include "base_graph.hpp"

class Tree : public Graph {
private:
    int m_size;
    Vector<std::pair<double, double > > m_nodes;
    Vector<Vector<std::pair<int, double > > > m_adjacency_list;
    //  LCA data
    int m_list_size;
    Vector<Vector<int > > m_rmq;
    Vector<int > m_position, m_depth, m_list, m_log;
    Vector<double > m_partial_sum;

    void DFS(int node, int father, int level);
    void ComputeRMQ();

protected:
    double ComputeDistance(std::pair<double, double >, std::pair<double, double >) override;
    void PrecomputeData();
    int LCA(int u, int v);

public:
    Tree();
    ~Tree();
    double GetDistance(const int u, const int v) override;
    void AddEdge(const int u, const int v);
    void ResizeGraph(const int size);
    void CreateGraph() override;
};


Tree::Tree() {

}


Tree::~Tree() {

}


double Tree::ComputeDistance(std::pair<double, double > a, std::pair<double, double > b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


int ComputeLog(const int value) {
    int power = 0;

    while ((1 << power) < value) {
        power++;
    }

    return power;
}


void Tree::ResizeGraph(const int size) {
    m_size = size;
    m_nodes.Resize(size + 1);
    m_adjacency_list.Resize(size + 1);

    //  Resize data structures needed for computing the LCA
    m_rmq.Resize(ComputeLog(size) + 2);
    for (int i = 0; i < static_cast<int >(m_rmq.Size()); i++) {
        m_rmq[i].Resize(size + 2, 0);
        //m_rmq[i].Fill(0);
    }

    m_position.Resize(size + 2, 0); //m_position.Fill(0);
    m_depth.Resize(2 * (size + 2), 0); //m_depth.Fill(0);
    m_list.Resize(2 * (size + 2), 0); //m_list.Fill(0);
    m_log.Resize(2 * (size + 2), 0); //m_log.Fill(0);
    m_partial_sum.Resize(size + 2, 0); //m_position.Fill(0);
}


void Tree::AddEdge(const int u, const int v) {
    double node_distance = ComputeDistance(m_nodes[u], m_nodes[v]);
    m_adjacency_list[u].PushBack(std::make_pair(v, node_distance));
    m_adjacency_list[v].PushBack(std::make_pair(u, node_distance));
}


void Tree::CreateGraph() {
    std::cout << "Number of vertices:\n";
    int size; std::cin >> size;
    ResizeGraph(size);

    std::cout << "Give the coordinates of the vertices, each on a separate line:\n";
    for (int i = 1; i <= size; i++) {
        std::cin >> m_nodes[i].first >> m_nodes[i].second;
    }

    std::cout << "Give the edges, each on a separate line:\n";
    for (int i = 1; i < size; i++) {
        int u, v; std::cin >> u >> v;
        AddEdge(u, v);
    }

    PrecomputeData();
}


void Tree::DFS(int node, int father, int level) {
    m_list[++m_list_size] = node;
    m_depth[m_list_size] = level;
    m_position[node] = m_list_size;

    for (auto it = m_adjacency_list[node].begin(); it != m_adjacency_list[node].end(); it++) {
        if (it->first != father) {
            m_partial_sum[it->first] = m_partial_sum[node] + it->second;
            DFS(it->first, node, level + 1);
            m_list[++m_list_size] = node;
            m_depth[m_list_size] = level;
        }
    }
}


void Tree::ComputeRMQ() {
    for (int i = 2; i <= m_list_size; i++) {
        m_log[i] = m_log[i >> 1] + 1;
    }

    for (int i = 1; i <= m_list_size; i++) {
        m_rmq[0][i] = i;
    }

    for (int i = 1; (1 << i) < m_list_size; i++) {
        int last_position = m_list_size - (1 << i) + 1;

        for (int j = 1; j <= last_position; j++) {
            m_rmq[i][j] = (m_depth[m_rmq[i - 1][j]] < m_depth[m_rmq[i - 1][j + (1 << (i - 1))]]) ? m_rmq[i - 1][j] : m_rmq[i - 1][j + (1 << (i - 1))];
        }
    }
}


int Tree::LCA(int u, int v) {
    int a = m_position[u], b = m_position[v];

    if (a > b) {
        std::swap(a, b);
    }

    std::cout << "From " << a << " to " << b << '\n';

    int level = m_log[b - a + 1];
    return (m_depth[m_rmq[level][a]] < m_depth[m_rmq[level][b - (1 << level) + 1]]) ? m_list[m_rmq[level][a]] : m_list[m_rmq[level][b - (1 << level) + 1]];
}


void Tree::PrecomputeData() {
    m_depth[1] = 1; m_list_size = 0;
    DFS(1, 0, 1);

    for (int i = 1; i <= m_size; i++) {
        std::cout << i << ": " << m_partial_sum[i] << '\n';
    }

    ComputeRMQ();
}


double Tree::GetDistance(const int u, const int v) {
    int lca = LCA(u, v);

    std::cout << lca << '\n';

    double answer = m_partial_sum[u] + m_partial_sum[v] - 2 * m_partial_sum[lca];
    return answer;
}

#endif  //  MAP_TREE_H
