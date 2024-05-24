#ifndef _W_GRAPH_H
#define _W_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include "vertice.h"

class WGraph {
public:

    WGraph();
    WGraph(int vertices);
    std::vector<std::vector<float>> mPesos; 
    std::vector<ver> vs;


    bool insert(ver valor);
    bool addPeso(int valor1, int valor2);
    bool deleteV(int valor);
    std::vector<ver> retConexiones(int val);
    bool addPesos();
    void printMPesos();
    std::vector<ver> prim_rec(int valor, std::vector<ver> & visited);
    std::vector<ver> prim();
    int minDistance(std::vector<int> & dist, std::vector<bool>& spSet, int V);
    void dijkstra(std::vector<std::vector<int>>&graph, int src);

};

#include "wgraph.hxx"

#endif
