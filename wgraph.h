#ifndef _W_GRAPH_H
#define _W_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include "vertice.h"

class WGraph {
public:
    WGraph(int vertices);
    std::vector<std::vector<bool>> mAdyacencia;
    std::vector<std::vector<float>> mPesos; // Fixed: Added missing closing bracket
    std::vector<ver> vs;
    bool insert(ver valor);
    bool addArista(int valor1, int valor2);
    bool addPeso(int valor1, int valor2, float peso);
    bool deleteV(int valor);
    void printMAdyacencia(); 
    void iterativeDFS(int valor);
    std::vector<ver> retConexiones(int val);
    void recursiveDFS(int valor);
    void recursiveDFSHelper(int valor, std::vector<ver>& visited);
};

#include "wgraph.hxx"

#endif
