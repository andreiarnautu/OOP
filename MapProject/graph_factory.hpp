/**
  *  Worg
  */
#ifndef MAP_GRAPH_FACTORY_H
#define MAP_GRAPH_FACTORY_H

class GraphFactory {
public:
    static Graph* GenerateGraph(const int type) {
        switch (type) {
            case 0 : return new GeneralGraph;
            case 1 : return new CompleteGraph;
            case 2 : return new LineGraph;
            case 3 : return new Tree;
            case 4 : return new DirectedAcyclicGraph;
            default : return new GeneralGraph;
        }
    }
};

#endif  //  MAP_GRAPH_FACTORY_H
