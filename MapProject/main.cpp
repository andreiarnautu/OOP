/**
  *  Worg
  */
#include <iomanip>
#include <utility>
#include <iostream>

#include "vector.hpp"

#include "base_graph.hpp"
#include "general_graph.hpp"
#include "complete_graph.hpp"
#include "line_graph.hpp"
#include "tree.hpp"
#include "dag.hpp"

#include "graph_factory.hpp"


void Interface() {
    std::cout << "Welcome to RoadApp, the application where you can turn a map from real-life into an abstract graph! I know, sometimes dreams do come true...\n";


    Vector<std::pair<Graph*, int > > graph_list;

    while (true) {
        std::cout << "\n\nOptions:\n\t0 - stop the program\n\t1 - add a new region\n\t2 - add a new road in an existing region\n\t3 - compute the distance between 2 nodes belonging to the same region.\nInsert the desired number and press 'Enter'.\n";

        int command; std::cin >> command;

        if (command < 0 || command > 3) {
            std::cout << "Instructions unclear, redirecting...\n";
        } else if (command == 0) {
            break;
        } else if (command == 1) {
            std::cout << "What type of graph should represent your region? Options:\n\t0 - general unoriented graph\n\t1 - complete graph\n\t2 - unoriented line graph\n\t3 - tree\n\t4 - directed acyclic graph\nInsert the desired number and press 'Enter'.\n";

            int graph_type; std::cin >> graph_type;

            if (graph_type < 0 || graph_type > 4) {
                continue;
            } else {
                Graph *new_graph = GraphFactory::GenerateGraph(graph_type);
                new_graph->CreateGraph();
                graph_list.PushBack(std::make_pair(new_graph, graph_type));

                std::cout << "The region #" << static_cast<int >(graph_list.Size()) - 1 << " was successfully created.\n";
            }
        } else if (command == 2) {
            std::cout << "What's the number of the region where the new road will be added? Insert it and press 'Enter'.\n";

            int region_number; std::cin >> region_number;

            if (region_number < 0 || region_number >= static_cast<int >(graph_list.Size())) {
                std::cout << "Oops, seems like we don't have region #" << region_number << " in our databases...while we look it up you can enter other commands. Redirecting...\n";
            } else if (graph_list[region_number].second != 0 && graph_list[region_number].second != 4) {
                std::cout << "Hmm, our scientists say that region #" << region_number << " can not support a road addition, otherwise it would become unstable. Maybe try something else. Redirecting...\n";
            } else {
                std::cout << "Enter the new road to be added to the region:\n";
                int u, v; std::cin >> u >> v;
                graph_list[region_number].first->AddEdge(u, v);
                std::cout << "Road added successfully.\n";
            }
        } else {
            std::cout << "What's the number of the region where the nodes are located?\nInsert it and press 'Enter'.\n";
            int region_number; std::cin >> region_number;

            if (region_number < 0 || region_number >= static_cast<int >(graph_list.Size())) {
                std::cout << "Oops, seems like we don't have region #" << region_number << " in our databases...while we look it up you can enter other commands. Redirecting...\n";
            } else {
                std::cout << "Enter the desired nodes. Careful, their order might matter. If the nodes inserted are invalid or if there is no valid path between them, then the result -1.0 will be returned.\n";

                int u, v; std::cin >> u >> v;
                std::cout << "The distance is: ";
                std::cout << std::fixed << std::setprecision(5) << graph_list[region_number].first->GetDistance(u, v) << '\n';
            }
        }
    }

    for (int i = 0; i < static_cast<int >(graph_list.Size()); i++) {
        delete graph_list[i].first;
    }
}

int main() {
    // Graph *general_graph = GraphFactory::GenerateGraph(4);
    // general_graph->CreateGraph();
    //
    // std::cout << std::fixed << std::setprecision(5) << general_graph->GetDistance(1, 3) << '\n';
    // std::cout << std::fixed << std::setprecision(5) << general_graph->GetDistance(3, 5) << '\n';
    //
    // delete general_graph;
    Interface();
    return 0;
}
