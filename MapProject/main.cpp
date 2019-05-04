/**
  *  Worg
  */
#include <iomanip>
#include <iostream>

#include "vector.hpp"

#include "base_graph.hpp"
#include "general_graph.hpp"
#include "complete_graph.hpp"
#include "line_graph.hpp"

#include "graph_factory.hpp"

int main() {
//     GeneralGraph g;
//
//     g.CreateGraph();
//
//     std::cout << std::fixed << std::setprecision(5) << g.GetDistance(1, 3) << '\n';
//     std::cout << std::fixed << std::setprecision(5) << g.GetDistance(2, 5) << '\n';

    Graph *general_graph = GraphFactory::GenerateGraph(0);
    general_graph->CreateGraph();

    std::cout << std::fixed << std::setprecision(5) << general_graph->GetDistance(1, 3) << '\n';
    std::cout << std::fixed << std::setprecision(5) << general_graph->GetDistance(2, 5) << '\n';

    delete general_graph;
    return 0;
}
