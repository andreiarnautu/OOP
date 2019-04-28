/**
  *  Worg
  */
#include <iomanip>
#include <iostream>

#include "vector.hpp"
#include "base_graph.hpp"
#include "general_graph.hpp"

int main() {
    GeneralGraph g;

    g.CreateGraph();

    std::cout << std::fixed << std::setprecision(5) << g.GetDistance(1, 3) << '\n';
    std::cout << std::fixed << std::setprecision(5) << g.GetDistance(2, 5) << '\n';
    return 0;
}
