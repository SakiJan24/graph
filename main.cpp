#include <iostream>
#include "graph.h"
#include "wgraph.h"
#include "vertice.h"
#include "circuit.h"
#include <sstream>
#include <string>
#include <vector> 
#include <fstream>

bool leerCircuito( Lote& circuitos, const std::string& nomArch);
// Buenas, en este main estoy hacinedo las pruebas de este grafo, WGraph, no utilizar
int main(int argc, char* argv[]) {
    



    /*if(argc < 2) {

        std::cerr<< "Uso: " << argv[ 0 ] << " archivo_entrada" << std::endl;
        return -1;
    }*/

    // Hago la instancia de WGraph
    // Para inserción de datos lo que hago es meterle los datos a un struct de tipo vértice varias veces
    // falta hacer la lectura del archivo ahorita lo hago
    Lote circuitos;


    bool leyo = leerCircuito(circuitos, "in_0.txt");

    if(leyo) {

        circuitos.escribirArchivo();
    }


    /*
    WGraph grafo;
    ver elVertice;

    elVertice.id = 0;
    elVertice.x = 5.10686;
    elVertice.y = 9.71466;
    grafo.insert(elVertice);
    

    elVertice.id = 1;
    elVertice.x = 2.80042;
    elVertice.y = 5.46107;
    grafo.insert(elVertice);

    elVertice.id = 2;
    elVertice.x = 7.19269;
    elVertice.y = 1.13281;
    grafo.insert(elVertice);

    elVertice.id = 3;
    elVertice.x = 4.71483;
    elVertice.y = 5.9254;
    grafo.insert(elVertice);

    elVertice.id = 4;
    elVertice.x = 9.44318;
    elVertice.y = 4.50918;
    grafo.insert(elVertice);

    elVertice.id = 5;
    elVertice.x = 3.36351;
    elVertice.y = 8.47684;
    grafo.insert(elVertice);

    // Ac[a] lo que se hace es que se va generar la matriz de pesos del grafo basado en los v[ertice ingresados]
    grafo.addPesos();

    // Esta funci[on ] imprime todo los n[u]meros dentro de la matriz de pesos
    grafo.printMPesos();



    // Ac[a] va el recorrido:

    std::vector<ver> recorrido;
    recorrido = grafo.prim();

    for (int i = 0; i < grafo.vs.size(); i++) {
        
        std::cout << recorrido[i].id << std::endl;
    }
    */



    return 0;
}



bool leerCircuito( Lote& circuitos, const std::string& nomArch) {


    std::ifstream entrada( nomArch.c_str());
    if(!entrada) {

        return false;
    }
    int cantCircuitos = 0;
    entrada >> cantCircuitos;

    for (int i = 0; i < cantCircuitos && !entrada.eof(); i++) {
        /* code */
        int cantHuecos = 0;
        entrada>> cantHuecos;
        WGraph circuito(cantHuecos);
        for (int j = 0; j < cantHuecos; j++) {
            /* code */
            ver nuevoVertice;
            float x = 0, y = 0;

            entrada >> x >> y;
            nuevoVertice.id = j;
            nuevoVertice.x = x;
            nuevoVertice.y = y;
            circuito.insert(nuevoVertice);
          //  std::cout << x << "," << y << std::endl;
        }
        

        circuitos.grafos.push_back(circuito);
        
    }
    entrada.close();
    return true;
}