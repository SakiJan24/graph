#include <iostream>
#include "graph.h"
#include "wgraph.h"
#include "vertice.h"



// Buenas, en este main estoy hacinedo las pruebas de este grafo, WGraph, no utilizar
int main() {
    

    // Hago la instancia de WGraph
    // Para inserción de datos lo que hago es meterle los datos a un struct de tipo vértice varias veces
    // falta hacer la lectura del archivo ahorita lo hago
    WGraph grafo(6);
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





    return 0;
}