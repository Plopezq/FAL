// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


typedef struct {
    int numPartJug = 0; //Numero de partidos que se han jugado realmente, hasta la ronda pediad incluida --> comun a todas las llamadas
    bool preseJug; //Indica si se presento alguno de los jugadores --> para cada llamada
    int numRond = 0; //Indica la ronda actual a la que corresponden esos datos --> para cada llamada
}tSol;
// función que resuelve el problema
tSol resolver(vector<string> const &jugadores, int ini, int fin, int ronda) {

    if (ini + 1 == fin) { // Caso base -> Vector de dos elementos
        tSol solucion;
        string jugador1 = jugadores[ini];
        string jugador2 = jugadores[fin];
        solucion.numRond += 1; //Incremento la ronda
        if (jugador1 == "NP" && jugador2 == "NP") { //No se presenta ningun jugador
            solucion.preseJug = false;
        }
        else { //Se ha presentado al menos un jugador
            solucion.preseJug = true;
        }
    }
    else { // Vector de 2 o mas elementos 
        int m = (ini + fin) / 2;

        tSol solIzq = resolver(jugadores, ini, m, ronda);
        tSol solDer = resolver(jugadores, m, fin, ronda);


    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numJug = -1;
    int ronda = -1;
    vector<string> jugadores;

    cin >> numJug;
    if (!std::cin)
        return false;
    cin >> ronda;
    string aux = "";
    for (int i = 0; i < numJug; i++) {
        cin >> aux;
        jugadores.push_back(aux);
    }

    tSol sol = resolver(jugadores, 0, numJug, ronda);

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}