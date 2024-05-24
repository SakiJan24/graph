#include <vector> 
#include <iostream> 
/*TAD Filtro

Estado:
- proceso, cadena de caracteres, contiene el nombre del filtro o proceso que se va a hacer


TAD Grafo

Estado:
- mAdyacencia, colección de colecciones de valores enteros, contiene los valores de las entradas y las salidas de de un filtro 
- filtros, todos los filtros existentes dentro del la aplicación de procesamiento de imágenes

Comportamiento:
- insertarNuevoFiltro(entradas, salidas, filtro):booleano, dados los valores de las entradas, es decir, los nombres de los filtros de entrada así cómo las alidas, además, un filtro lleno, es decir, que tenga los valores de sus entradas y salidas junto con su nombre, agregar un nuevo filtro dentro del grafo de procesamiento de imágenes y conectar las respectivas entradas y salidas cone ste nuevo filtro //preguntar que contienen las entradas y salidas

- calcularCosto(filtro1, filtro2): booleano; dados dos filtros, se busca calcular el costo computacional entre esos dos filtros //preguntar al profe si es la ruta más corta

TAD AplicacionPorcesamiento
Grafoi

bool Grafo::calcularCosto( Filtro filtro1,  Filtro filtro 

================================================================================================================================================================================
*/

/*
TAD Habitacion:

Estado: 
- id, este es un identificador único para distinguir entre una habtiación y otra
- objetos, este es una colección de cadenas de caracteres la cuál tiene almacenada los papeles y las estrellas dentro de una habitación


Comportamiento: 
-

TAD Player:

Estado: 
- nombre, cadena de caracteres que identifica al jugador de la partida
- objetosRecogidos, coleccción de cadena de caracteres que contiene todos los objetos recogidos por el jugador hasta el momento                           
Comportamiento:
- anadirObjeto(cadena del objeto); esta función inserta un objeto dentro de la colección de objetos recogidos de un jugador

TAD Grafo

Estado:
- mAdyacencia, es una colección de cadenas de caracteres que contiene si una habitación está conectada a otra dependiendo de sí tiene alguna letra N (Norte), S (Sur), E (Este) o W (Oeste)
- habtiaciones, es una colección de TAD habitación, la cuál también es utilizada para ubicarlas y hacer el recorrido con la matriz de adyacenci


Comportamiento: 
- recogerObjeto(cadena de carateres): booleano; dada un cadena de caracteres se recoge un papel o una estrella dentro de una habitación, esta función inserta dentro del los objetos del jugador el objeto
encontrado y luego lo quita de los objetos dentro de la habitación.
- dijkstra(inicio, fin): caminos; esta función obtiene los caminos oṕtimos para llegar a todos lo vértices, sin embargo, de este solo nos va a importar el camino más corto desde una estrella a un estrella 
pŕoxima, desde el inicio hasta una estrella o desde el inicio a la salida
- dfs(): colección de habitaciones; este algoritmo va a seleccionar el vértice de la primera habitación dentro de la mazmorra y va a mandar la función dfs recursivo a recorrer la mazmorra
- dfs_recursivo(vertInicio): colección de habitaciones, este algoritmo va a recorrer toda la mazmorra de manera recurrente y va a ir coleccionando todas las habitaciones en dónde se encuentra una estrella,
cuando ya no queden más habitaciones por recorrer retorna la colección de las habitaciones con las estrellas. 


TAD Sistema

Estado:
Mazmorra, es un TAD de tipo grafo que contien todas las habitaciones

Comportamiento: 
recogerTodasEstrellas():colección de cadena de caracteres,esta función recorre toda la mazmorra, recoge las estrellas y retorna
los comandos para poder recoger todas las estrellas.
salirMazmorra(): colección de cadena de caracteres, esta función recorre todas la mazmorra y retorna los comandos necesarios para 
poder llegar a la salida de la mazmorra.

*/


std::vector<Habitacion> Grafo::retConexiones(Habitacion habi) {

    int index = 0;
    for(int i = 0; i < this->habitaciones.size(); i++) {

        if(this->habitaciones[i] == habi.id) {

            index = i;
            break;
        }
    }

    std::vector<Habitacion> conexiones;
    for(int i = 0; i < this->habitaciones.size(); i++) {

        if(this->mAdyacencia[index][i] != "") {

            conexiones.push_back(this->habitaciones[i]);
        }
    }

    return conexiones;
}


std::vector<Habitacion> Grafo::dfs() {

    std::vector<Habitacion> visited;
    std::vector<Habitacion> estrellas;
    return this->recursivedfs(this->habitaciones[0], visited, estrellas );
}

std::vector<Habitacion> Grafo::recursivedfs(Habitacion habi, std::vector<Habitacion>&visited, std::vector<Habitacion>& estrellas) {

    if(visited.size() == this->habitaciones.size()) {

        return estrellas;
    }

    visited.push_back(habi);
    for(int i = 0; i < habi.objetos.size(); i++) {

        if(habi.objetos[i] == "estrella") {

            estrellas.push_back(habi);
        }
    }


    std::vector<Habitacion> conexiones = retConexiones(habi);}

    for(habitacion conexion: conexiones) {

        typename std::vector<Habitacion>::iterator it2 = visited.begin();
        for(; it2 != visited.end(); it2++) {

            if(it2->id == conexion.id) {

                break;
            }
        }

        if(it2 == visited.end()) {

                recursivedfs()
        }

    }
}



std::vector<string> Sistema::recogerEstrellas() {

    std::vector<Habitacion> estrellas = this->masmorra.dfs();
    std::vector<std::string> comandos;
    for (int i = 0; i < estrellas.size(); i++) {

        if(i == 0) {
            std::vector<int> dist;
            std::vector<int> predecessors;
            this->dijkstra(estrellas[i].id, dist, predecessors );
            std::stack<Habitacion> pred;
            printPath(predecessors, estrellas[i+1], pred);
            for (int j = 0; j < pred.size(); j++) {
                
                if(pred.size() == 1) {

                    comandos.push_back("recoger estrella");
                    pred.pop();
                    break;
                }

                Habitacion conectada = pred.top();
                pred.pop();
                comandos.push_back(this->getPuertasConexion(conectada.id, pred.top().id));
            }
            

        }
    }

    std::vector<int> dist2;
    std::vector<int> predecessors2;
    this->dijkstra(estrellas[estrellas.size() -1].id,dist2, predecessors2 );
    std::stack pred2;
    printPath(predecessors2, )
    for (int j = 0; j < pred.size(); j++) {
                
            if(pred.size() == 1) {

                comandos.push_back("recoger estrella");
                pred.pop();
                break;
            }

            Habitacion conectada = pred.top();
            pred.pop();
            comandos.push_back(this->getPuertasConexion(conectada.id, pred.top().id));
    }
    


    std::vector<std::string> comandos2 = 
    
}

std::char Grafo::getPuertaConexion(int id1, int id2) {
    int index1 = 0, index2 = 0;
    for (int i = 0; i < this->habitaciones.size(); i++) {

        if(this->habitaciones[i].id == id1) {

            index1 = i;
        }

        if(this->habitaciones[i].id == id2) {

            index2 = i;
        }
    }

    return this->mAdjacency[index1][index2];
    
}

std::stack<Habitacion> printPath(std::vector<int>& predecessors, int vertex, std::stack <Habitacion> &pred){

    if(vertext == -1) {

        return pred;
    }

    printPath(predecessors, predecessors[vertex]);
    pred.push_back(vertex);
}

void dijkstra(int src, std::vector<int>& dist, std::vector<int> &predecessors ) {

    int n = this->adjMatrix.size();
    dist.assign(n, INT_MAX);
    std::vector<bool> visited(n, false);
    predecessors.assign(n,-1);

    dist[src] = 0;

    for (int count = 0; count < n;  count++) {

        //Find the vertext with the minimum distance from the set of vertices not yet processed
        int minDistance = INT_MAX, minIndex = -1;
        for(int v = 0; v < n; v++) {

            if(!visited[v] && dist[v] <= minDistance) {

                minDistance = dist[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = true;

        for(int v = 0; v < n; v++) {

            if(!visited[v] && this->adjMatrix[u][v] != '' && dist[u] != INT_MAX && dist[u] + 1 < dist[v]) {

                dist[v] = dist[u] +1;
                predecessors[v] = u;
            }
        }
    }
    
}


std::vector<std::string> Grafo::salirMazmorra(Habitacion habiInicio ) {

    std::vector<std::string> comandos;
    std::vector<int> dist;
    std::vector<int> predecessors;
    this->dijkstra(habiInicio.id, dist, predecessors);
    std::stack<Habitacion> pred;

    printPath(predecessors, estrellas[0], pred);
    for (int j = 0; j < pred.size(); j++) {
                
        if(pred.size() == 1) {

            comandos.push_back("recoger estrella");
            pred.pop();
            break;
        }
        
        Habitacion conectada = pred.top();
        pred.pop();
        comandos.push_back(this->getPuertasConexion(conectada.id, pred.top().id));
     }

     return comandos;
}