#include <iostream>
#include <sstream>
#include <string>
#include <vector> 
#include <fstream>
// TODO #1: incluir archivo s de cabecera que contienen:
// El grafo a usar
#include "wgraph.h"
// Los vertices
#include "vertice.h"
// El TAD que almacena los grafos
#include "lote.h"


bool leerCircuito( Lote& circuitos, const std::string& nomArch);
int main(int argc, char* argv[]) {

    if(argc < 2) {

        std::cerr<< "Uso: " << argv[ 0 ] << " archivo_entrada" << std::endl;
        return -1;
    }

   // Declarar la colección de grafos a usuar
    Lote circuitos;

    // Leer el archivo que el usuario haya ingresado
    bool leyo = leerCircuito(circuitos, argv[1]);


    // Si este archivo fue leído correctamente se escribe el grafo con las distancias ordenadas de menor a mayor empezando por el origen
    if(leyo) {

        circuitos.escribirArchivo(argv[1]);
    }


    return 0;
}





// Esta función lee el archivo completo e inserta los grafos dentro de la estructura circuitos
bool leerCircuito( Lote& circuitos, const std::string& nomArch) {


    std::ifstream entrada( nomArch.c_str());
    if(!entrada) {

        return false;
    }
    int cantCircuitos = 0;
    entrada >> cantCircuitos;

    for (int i = 0; i < cantCircuitos && !entrada.eof(); i++) {
        
        
        
        int cantHuecos = 0;
        entrada>> cantHuecos;

        //Esta es una excepción en dónde se pide ingresar un grafo de 0 vértices
        //En este caso se tiene pasar a la siguiente línea para poder ver otro grafo
        if (cantHuecos == 0) {
           
           entrada>> cantHuecos;
           i++;
        }
        else {
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
        
    }
    entrada.close();
    return true;
}