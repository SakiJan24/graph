#include "lote.h"
#include "vertice.h"
#include <fstream>


Lote::Lote() {


}

bool Lote::escribirArchivo(std::string arch) {

    std::string archi;
    if(arch == "in_0.txt") {
        
        archi = "out_0.txt";
    }

    else if(arch == "in_1.txt") {
        
        archi = "out_1.txt";
    }

    else if(arch == "in_2.txt") {
        
        archi = "out_2.txt";
    }


    bool writen = false;
    std::ofstream out(archi);
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