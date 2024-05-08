#include "circuit.h"
#include "vertice.h"
#include <fstream>


Lote::Lote() {


}

bool Lote::escribirArchivo() {

    bool writen = false;
    std::ofstream out("out_2.txt");
    if(!out) {

        return writen;
    }

    out << this->grafos.size() << "\n";

    for (int i = 0; i < this->grafos.size(); i++)
    {
        out << this->grafos[i].vs.size() << "\n"; 
        this->grafos[i].addPesos();
       // this->grafos[i].printMPesos();
        std::vector<ver> grafo = this->grafos[i].prim();

        for (int j = 0; j < grafo.size(); j++) {

            out << grafo[j].x << " " << grafo[j].y << "\n";
        }
        

    }
    

    out.close();
    writen = true;
    return writen;
}