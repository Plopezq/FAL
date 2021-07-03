// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//Funcion que escribe el vector solucion
void escribirSol(vector<int> const& solucion) {
    for (int z : solucion) {
        if (z == 0) { //AZUL
            cout << "azul ";
        }
        else if (z == 1) { //ROJO
            cout << "rojo ";
        }
        else { //z == 2 --> VERDE
            cout << "verde ";
        }
    }
    cout << endl;
}

// función que resuelve el problema
void permutaciones(int const altura, int k, vector<int>& sol){
    for (int i = 0; i < 3; i++) {
        sol[k] = i;
        if (k == (altura - 1)) { //Es solucion, tiene la altura deseada
            escribirSol(sol);
        }
        else {
            permutaciones(altura, k + 1, sol);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int altura = -1;
    cin >> altura;
    if (altura == 0)
        return false;

    vector<int> sol(altura); //     0 azul, 1 rojo, 2 verde

    permutaciones(altura,0,sol);
    cout << endl;

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
