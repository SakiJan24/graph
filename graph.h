#ifndef _GRAFO_H
#define _GRAFO_H
#include <iostream>
#include <vector>
#include <queue>
template <class T>
class Grafo {

    public:
        Grafo();
        Grafo(int vertices);
        std::vector<std::vector<bool>>mAdyacencia;
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

#include "graph.hxx"
#endif
