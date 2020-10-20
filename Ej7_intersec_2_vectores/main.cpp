// Nombre del alumno: Pablo López Martín
// Usuario del Juez: E40

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
vector<int> resolver(vector<int> const& v1, vector<int> const& v2) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v1;
    vector<int> v2;

    while (v1[v1.size()] != 0) { //Lectura del vector 1
        int aux;
        cin >> aux;
        v1.push_back(aux);
    }
    while (v2[v2.size()] != 0) { //Lectura del vector 2
        int aux;
        cin >> aux;
        v2.push_back(aux);
    }

    vector<int> sol = resolver(vector<int> const& v1, vector<int> const& v2);
    // escribir sol


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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}