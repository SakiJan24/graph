#ifndef _LOTE_H_
#define _LOTE_H_
#include "vertice.h"
#include "wgraph.h"
#include <vector>
#include <queue>

class Lote {


    public:
        std::vector<WGraph> grafos;

        Lote();
        bool escribirArchivo(std::string arch);
   


};


#include "lote.hxx"
#endif