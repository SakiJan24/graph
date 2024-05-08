#include "wgraph.h"
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm>
#include <cmath>

WGraph::WGraph(int vertices) {
    
    this->mAdyacencia.resize(vertices, std::vector<bool>(vertices, 0));
    this->mPesos.resize(vertices, std::vector<float>(vertices));
    ver vacio;
    vacio.id = -1;
    for (int i = 0; i < vertices; i++) {

        this->vs.push_back(vacio);
    }
    
    
}


bool WGraph::insert(ver valor) {


    bool insertado = false;
    //Caso grafo empty
    for(int i = 0; i < this->vs.size() && !insertado; i++) {

        if(vs[i].id == -1) {

            vs[i] = valor; 
            insertado = true;

        }
    }

    if(!insertado) {

        this->vs.push_back(valor);
        this->mAdyacencia.resize(vs.size());
        this->mPesos.resize(vs.size());
        for(int i = 0; i < this->mAdyacencia.size(); i++) {

            this->mAdyacencia[i].resize(vs.size(), 0);
            this->mPesos[i].resize(vs.size(), 0);
        }
        insertado = true;

    }
    return insertado;
}


bool WGraph::addArista( int valor1, int valor2) {

    bool insertada = false;
    int indice1=-1, indice2=-1;
    for(int i = 0; i < this->vs.size(); i++) {

        if(valor1 == vs[i].id){

            indice1 = i;
        }

        if(valor2 == vs[i].id){

            indice2 = i;
        }

    }

    if(indice2 == -1 || indice1 == -1) {

        insertada = false;
    }

    else {

        this->mAdyacencia[indice1][indice2] = true;
    }
    return insertada;
}



bool WGraph::addPeso( int valor1, int valor2) {

    bool insertada = false;
    int indice1=-1, indice2=-1;

    for(int i = 0; i < this->vs.size(); i++) {

        if(valor1 == vs[i].id){

            indice1 = i;
        }

        if(valor2 == vs[i].id){

            indice2 = i;
        }

    }



    if(indice2 == -1 || indice1 == -1) {

        insertada = false;
    }

    else {

        std::cout << "Val1: " << valor1 << "," << valor2 <<std::endl;
        std::cout << "Primer valor: " << vs[indice1].x << "," << vs[indice1].y <<std::endl;
        std::cout << "Segundo valor: " << vs[indice2].x << "," << vs[indice2].y <<std::endl;
        // hago el calc de distancia
        float X = pow(static_cast<double>(vs[indice1].x-vs[indice2].x), 2);
        float Y = pow(static_cast<double>(vs[indice1].y-vs[indice2].y), 2);
        float distancia = sqrt(X+Y);
        this->mPesos[indice1][indice2] = distancia;
        std::cout << "distancia: " << distancia << std::endl; 
    }
    return insertada;

}


bool WGraph::deleteV(int valor) {

    bool eliminado = false;
    typename std::vector<ver>::iterator it = vs.begin();
    for(; it != vs.end(); it++) {

        if((it)->id == valor) {

            break;
        }
    }
    if(it!=vs.end()) {

        int index = std::distance(vs.begin(), it);
        this->vs.erase(vs.begin()+index);

        mPesos.erase(mPesos.begin()+index);
        mAdyacencia.erase(mAdyacencia.begin()+index);
        // eliminar la columna de la matriz de adyacencia
        for (int i = 0; i < mAdyacencia.size(); i++) {

            mAdyacencia[i].erase(mAdyacencia[i].begin()+index);
            mPesos[i].erase(mPesos[i].begin()+index);
        }

        eliminado = true;

    }
    return eliminado; 
}



void WGraph::printMAdyacencia() {
    // Iterate over each row of the matrix
    for (const auto& row : mAdyacencia) {
        // Print the elements of the row
        for (bool connection : row) {
            std::cout << connection << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}

void WGraph::printMPesos() {
    // Iterate over each row of the matrix
    for (const auto& row : mPesos) {
        // Print the elements of the row
        for (float connection : row) {
            std::cout << connection << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}


void WGraph::iterativeDFS(int valor) {

    std::queue<int> pila1;
    //std::queue<T> pila2;
    std::vector<int>visitados;
    pila1.push(valor);
    while(!pila1.empty()) {
            
        int v = pila1.front();
        pila1.pop();
        //pila2.pop();
        bool visitado = false;
        for(int k = 0; k < visitados.size() && !visitado; k++) {

            if(visitados[k] == v) {

                visitado = true;
            }
        }

        if(!visitado) {
            std::cout << v << "-";
            visitados.push_back(v);
            std::vector<ver> aristas = retConexiones(v);
            typename std::vector<ver>::iterator it = aristas.begin();

            for(; it != aristas.end(); it++) {

                pila1.push((it)->id);
                //pila2.push(v);
            }

        }
    
        
    }
}


std::vector<ver> WGraph::retConexiones(int val) {

    int index;
    for(int i = 0; i < vs.size(); i++) {

        if(vs[i].id == val) {

            index = i;
        }
    }

    std::vector<ver> conexiones;
    for(int i = 0; i < vs.size(); i++) {
    
        conexiones.push_back(vs[i]); 
        
    }
    //std::sort(conexiones.begin(), conexiones.end());  

    return conexiones;
}


void WGraph::recursiveDFS(int valor) {
    std::vector<ver> visited;
    recursiveDFSHelper(valor, visited);
}


void WGraph::recursiveDFSHelper( int valor, std::vector<ver>& visited) {
    ver vertice;
    for(int i = 0; i < vs.size(); i++ ) {

        if(vs[i].id == valor) {

            vertice = vs[i];
        }
    }
    visited.push_back(vertice);
    std::cout << valor << " ";

    std::vector<ver> conexiones = retConexiones(valor);
    for (ver conexion : conexiones) {

        /// ACA 
        /// EST[A]


        /// EL ERROR
        typename std::vector<ver>::iterator it2 = visited.begin();
        for(; it2 != visited.end(); it2++) {

            if((it2)->id == conexion.id) {

                break;
            }
    }
        if ( it2 == visited.end()) {
            recursiveDFSHelper(conexion.id, visited);
        }
/*
        else {

            break;
        }*/
    }
}

bool WGraph::addPesos() {

    for(int i = 0; i < vs.size(); i++) {
        
        for(int j = 0; j < vs.size(); j++) {
        
            this->addPeso(i,j);
            this->addPeso(j,i);
        }
    }

    return true;
}

