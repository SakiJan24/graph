#ifndef _W_GRAPH_H
#define W_GRAPH_H
#include <iostream>
#include <vector>
#include <queue>
template <class T>
class WGraph {

    public:
        Grafo(int vertices);
        std::vector<std::vector<bool>>mAdyacencia;
        std::vector<std::vector<float> mPesos;
        std::vector<T>vs;
        bool insert(T valor);
        bool addArista(T valor1, T valor2);
        bool deleteV(T valor);
        void printMAdyacencia(); 
        void iterativeDFS(T valor);
        std::vector<T> retConexiones(T val);
        void recursiveDFS(T valor);
        void recursiveDFSHelper(T valor, std::vector<T>& visited);

};

#include "wgraph.hxx"
#endif
