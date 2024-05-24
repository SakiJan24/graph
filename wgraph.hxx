#include "wgraph.h"
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm>
#include <cmath>



WGraph::WGraph() {

}

WGraph::WGraph(int vertices) {
    
  
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
    
        this->mPesos.resize(vs.size());
        for(int i = 0; i < this->mPesos.size(); i++) {

            this->mPesos[i].resize(vs.size(), 0);
        }
        insertado = true;

    }
    return insertado;
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

        // hago el calc de distancia
        float X = pow(static_cast<double>(vs[indice1].x-vs[indice2].x), 2);
        float Y = pow(static_cast<double>(vs[indice1].y-vs[indice2].y), 2);
        float distancia = sqrt(X+Y);
        this->mPesos[indice1][indice2] = distancia;
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
        // eliminar la columna de la matriz de adyacencia
        for (int i = 0; i < mPesos.size(); i++) {

            mPesos[i].erase(mPesos[i].begin()+index);
        }

        eliminado = true;
    }
    return eliminado; 
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



bool WGraph::addPesos() {

    for(int i = 0; i < vs.size(); i++) {
        
        for(int j = 0; j < vs.size(); j++) {
        
            this->addPeso(i,j);
            this->addPeso(j,i);
        }
    }

    return true;
}


std::vector<ver> WGraph::prim() {

    ver chiqui = this->vs[0];
    std::vector<ver> visited;
    std::vector<ver> recorrido;
    for(int i = 0; i < this->vs.size(); i++) {


        if( (vs[i].x +vs[i].y) < (chiqui.x+chiqui.y)) {
            
            chiqui = vs[i];
        }
    }

    visited.push_back(chiqui);
    recorrido = prim_rec(chiqui.id, visited);
    return recorrido; 
}



std::vector<ver> WGraph::prim_rec(int valor, std::vector<ver>& visited) {

    if(visited.size() == this->vs.size()) {
        return visited;
    }

    ver loDist;
    float dist = 0;
    for(int i = 0; i < vs.size(); i++) {
        int k = 0;
        for(;k<visited.size(); k++) {

            if(visited[k].id == vs[i].id) {

                break;
            }
        }

        if(k == visited.size()) {
            
            float distancia = this->mPesos[visited.back().id][i];
            if(dist == 0 || distancia < dist) {

                dist = this->mPesos[valor][i];
                loDist= vs[i];
            }  
        }            
    }

    visited.push_back(loDist);

    return this->prim_rec(loDist.id, visited);

}


int WGraph::minDistance(std::vector<int> & dist, std::vector<bool>& spSet, int V) {

    
    int min = INT_MIN, min_index;

    for(int v = 0; v < V; v++) {

        if(!spSet[v] && dist[v] >= min) {

            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void WGraph::dijkstra(std::vector<std::vector<int>>&graph, int src) {

    int V = graph.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> sptSet(V,false);

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {

        int u = minDistance(dist,sptSet,V); 

        sptSet[u] = true;
    
        for(int v = 0; v < V; v++) {
            
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    std::cout << "Vertex distance from source" << std::endl;
    for(int i = 0; i < V; i++) { 
    
        std::cout << i << "\t" << dist[i] << std::endl;
    }


}

