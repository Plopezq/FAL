// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int  resolver(vector<int> const & datos, int const ini, int const fin) {

    //Caso base - vector de dos elementos
    if (ini + 1 == fin) {
        return datos[ini];
    }
    else {//Caso recursivo --> vector de 2 o mas elementos
        int mitad = (ini + fin) / 2;
        if (datos[mitad] > datos[mitad -1 ]) { //El punto de inflexion esta a la IZQUIERDA, ya que la funcion crece
            return resolver(datos, ini, mitad);
        }
        else { //El punto de inflexion esta a la DERECHA, ya que la funcion decrece
            return resolver(datos, mitad, fin);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num = -1;
    int aux = -1;
    vector <int> datos;
    cin >> num; //Numero de elementos del vector;
    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    if (!std::cin)
        return false;

    int sol = resolver(datos, 0, datos.size() );

    // escribir sol
    cout << sol << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("33sample.in");
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