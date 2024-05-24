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


#include <iostream>

using namespace std;

int main() {


	return 0;
}
