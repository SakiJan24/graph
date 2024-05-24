/*TAD Jugador

Estado:
-id, es un valor entero que es el numero con el que juega el jugador
- x, valor flotante que representa la coordenada en X en la que se encuentra el jugador
- y, valor floanteque representala coordenada en Y en la que se encuentra el jugador
- porcentajeAtaque, valor flotante que representa el valor del porcentaje de ataque de un jugador dado
- porcentajeDefensa, valor flotante que representa el valor del porcentaje de defensa de un jugador dado

Comportamiento:


TAD Equipo

Estado:
- jugadores, es una colección de tads tipo jugador la cuál contiene los cuatro jugadores del partido
- mJugadores, es una matriz la cuál contiene la efectividad entre el pase de cada jugador con cada jugador en la cancha

Comportamiento:
- efectividadPase(id1, id2):valorFlotante, esta función recibe el identificador de un jugador junto con otro y se usa la fórmula dada para calcular al efectivada del pase entre estos dos jugadores
- pasesÓptimos(idJugador): colección de distancia óptimas; dado un jugador se generan todas las secuencia d e pases óptimas para todos los demás jugadores, en este caso no se busca la efectivdad más baja (como en dijkstra normal) sino la efectividad más alta, por lo que son probabilidades.
- 

TAD Sistema

Estado:

Comportamiento:

*/

float Equipo::calcularEfectividadPase(int id1, int id2) {



	efectividad = 1 - ((sqrt(pow(jugadores[id1].x - jugadores[id2].y, 2) +  pow(jugadores[id1].x - jugadores[id2].y, 2)   )/133 ));
	this->mJugadores[id1][id2]  = efectividad;
	return efectividad;
}




// Utility function to find the vertex with the maximum distance value
int maxDistance(std::vector<float>& dist, std::vector<bool>& spSet, int V) {
    float max = -std::numeric_limits<float>::infinity();
    int max_index = -1;

    for (int v = 0; v < V; v++) {
        if (!spSet[v] && dist[v] >= max) {
            max = dist[v];
            max_index = v;
        }
    }

    return max_index;
}

void dijkstraLongestPath(std::vector<std::vector<float>>& graph, int src) {
    int V = graph.size();
    std::vector<float> dist(V, -std::numeric_limits<float>::infinity());  // Initialize distances to negative infinity
    std::vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in longest path tree

    dist[src] = 1.0;  // Distance of source vertex from itself is always 1.0 for multiplication

    for (int count = 0; count < V - 1; count++) {
        int u = maxDistance(dist, sptSet, V); // Pick the maximum distance vertex from the set of vertices not yet processed
        sptSet[u] = true; // Mark the picked vertex as processed

        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is greater than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != -std::numeric_limits<float>::infinity() && dist[u] * graph[u][v] > dist[v]) {
                dist[v] = dist[u] * graph[u][v];
            }
        }
    }

    // Print the longest distances
    std::cout << "Vertex distance from source" << std::endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == -std::numeric_limits<float>::infinity()) {
            std::cout << i << "\t- INF (unreachable)" << std::endl;
        } else {
            std::cout << i << "\t" << dist[i] << std::endl;
        }
    }
}


void Equipo::pasesOptimos(idJugador) {


}
#include <iostream>

using namespace std;

int main() {


	return 0;
}
