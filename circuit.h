#ifndef _CIRCUIT_H
#define _CIRCUIT_H
#include "vertice.h"
#include "graph.h"
#include "wgraph.h"
#include <vector>
#include <queue>

class Lote {


    public:
        std::vector<WGraph> grafos;

        Lote();
        bool escribirArchivo();


};


#include "circuit.hxx"
#endif