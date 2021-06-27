// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &datos, int const ini, int const fin) {

    //caso base - vector de dos elementos
    if (ini + 1 == fin) {

    }
    else {//caso recursivo
        int mitad = (ini + fin) / 2;
        if () {

        }
        else {

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    cin >> numElem;

    if (!std::cin)
        return false;
    //leo el vector
    vector<int> datos;
    int aux;
    for (int i = 0; i < numElem; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    int sol = resolver(datos, 0, datos.size());

    // escribir sol
    cout << sol << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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