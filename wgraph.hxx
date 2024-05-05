#include "wgraph.h"
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm>
template < class T >
WGraph<T>::WGraph(int vertices) {
    
    this->mAdyacencia.resize(vertices, std::vector<bool>(vertices, 0));
    this->vs.resize(vertices);
}

template <class T>
bool WGraph<T>::insert(T valor) {


    bool insertado = false;
    //Caso grafo empty
    for(int i = 0; i < this->vs.size() && !insertado; i++) {

        if(vs[i] == T{}) {

            vs[i] = valor;
            insertado = true;
        }
    }

    if(!insertado) {

        this->vs.push_back(valor);
        this->mAdyacencia.resize(vs.size());
        for(int i = 0; i < this->mAdyacencia.size(); i++) {

            this->mAdyacencia[i].resize(vs.size(), 0);
        }
        insertado = true;

    }
    return insertado;
}

template <class T>
bool WGraph<T>::addArista(T valor1, T valor2) {

    bool insertada = false;
    int indice1=-1, indice2=-1;
    for(int i = 0; i < this->vs.size(); i++) {

        if(valor1 == vs[i]){

            indice1 = i;
        }

        if(valor2 == vs[i]){

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

template <class T>
bool WGraph<T>::deleteV(T valor) {

    bool eliminado = false;
    typename std::vector<T>::iterator it = std::find(vs.begin(), vs.end(), valor);
    if(it!=vs.end()) {

        int index = std::distance(vs.begin(), it);
        this->vs.erase(vs.begin()+index);

        mAdyacencia.erase(mAdyacencia.begin()+index);
        // eliminar la columna de la matriz de adyacencia
        for (int i = 0; i < mAdyacencia.size(); i++) {

            mAdyacencia[i].erase(mAdyacencia[i].begin()+index);
        }

        eliminado = true;

    }
    return eliminado; 
}


template <class T>
void WGraph<T>::printMAdyacencia() {
    // Iterate over each row of the matrix
    for (const auto& row : mAdyacencia) {
        // Print the elements of the row
        for (bool connection : row) {
            std::cout << connection << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}

template <class T>
void WGraph<T>::iterativeDFS(T valor) {

    std::queue<T> pila1;
    //std::queue<T> pila2;
    std::vector<T>visitados;
    pila1.push(valor);
    while(!pila1.empty()) {
            
        T v = pila1.front();
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
            std::vector<T> aristas = retConexiones(v);
            typename std::vector<T>::iterator it = aristas.begin();
            for(; it != aristas.end(); it++) {

                pila1.push(*it);
                //pila2.push(v);
            }

        }
    
        
    }
}

template<class T>
std::vector<T> WGraph<T>::retConexiones(T val) {

    int index;
    for(int i = 0; i < vs.size(); i++) {

        if(vs[i] == val) {

            index = i;
        }
    }

    std::vector<T> conexiones;
    for(int i = 0; i < vs.size(); i++) {

        if(this->mAdyacencia[index][i] == true) {

            conexiones.push_back(vs[i]); 
        }
    }
    std::sort(conexiones.begin(), conexiones.end());  

    return conexiones;
}

template <class T>
void WGraph<T>::recursiveDFS(T valor) {
    std::vector<T> visited;
    recursiveDFSHelper(valor, visited);
}

template <class T>
void Grafo<T>::recursiveDFSHelper(T valor, std::vector<T>& visited) {
    visited.push_back(valor);
    std::cout << valor << " ";

    std::vector<T> conexiones = retConexiones(valor);
    for (T conexion : conexiones) {
        if (std::find(visited.begin(), visited.end(), conexion) == visited.end()) {
            recursiveDFSHelper(conexion, visited);
        }
    }
}
