#include <iostream>
#include "graph.h"

int main() {
    
    Grafo<int> elGrafo(5);
   
    
    elGrafo.insert(1);
    elGrafo.insert(2);
    elGrafo.insert(3);
    elGrafo.insert(4);
    elGrafo.addArista(1,2);
    elGrafo.addArista(1,3);
    elGrafo.addArista(2,4);
    elGrafo.printMAdyacencia();
    elGrafo.insert(5);
    elGrafo.addArista(4,5);
    std::cout << std::endl;
    std::cout << std::endl;

    elGrafo.insert(6);
    elGrafo.addArista(2,6);
    elGrafo.addArista(6,5);

    std::cout << "Se rompe cuando hago el print" << std::endl;
    elGrafo.printMAdyacencia();
    elGrafo.iterativeDFS(1);
    std::cout << std::endl;
    elGrafo.recursiveDFS(1);
    return 0;
}