
// Nombre y apellidos del alumno: Pablo López Martín
// Usuario del juez de clase: E40

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    int n;
    std::cin >> n;
    // Declaración de variables
    // Codigo del alumno
    int puntMax = n;
    int numJug = 0;

    while (n != 0) {
        // Aqui codigo del alumno
        if (n > puntMax) {
            numJug = 1;
            puntMax = n;
        }else if(n == puntMax) {
            numJug++;
        }
        std::cin >> n;
    }

    // Escribir el resultado
    // Codigo del alumno
    cout << puntMax << " " << numJug << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
