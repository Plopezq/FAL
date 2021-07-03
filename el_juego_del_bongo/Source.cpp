// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(vector<int> const &datos, int ini, int fin, int cantado) {
    if (ini + 1 == fin) { //caso base - vector de dos elementos
        if ((ini + cantado ) == datos[ini]) {
            return datos[ini];
        }
        else {
            return -1;
        }
    }
    else { //caso recursivo
        int mitad = (ini + fin) / 2;
        if ((cantado + mitad) < datos[mitad]) { //busco en la izquierda
            return resolver(datos, ini, mitad, cantado);
        }
        else { //busco en la derecha
            return resolver(datos, mitad, fin, cantado);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numeros;
    int cantado;

    cin >> numeros;
    cin >> cantado;
    vector<int> datos;
    int aux;

    for (int i = 0; i < numeros; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    int sol = resolver(datos, 0, datos.size(), cantado);

    // escribir sol
    if (sol == -1) cout << "NO" << endl;
    else cout << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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