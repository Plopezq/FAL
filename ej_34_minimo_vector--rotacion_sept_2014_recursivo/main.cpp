// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40

using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(vector<int> const& datos, int ini, int fin) {

    //Caso base - vector de dos elementos
    if (ini + 1 == fin) {
        return datos[ini];
    }
    else {//Caso recursivo --> vector de 2 o mas elementos
        int mitad = (ini + fin) / 2;
        if (datos[mitad] < datos[mitad - 1]) { //Busco a la derecha de la mitad
            return resolver(datos, mitad, fin);
        }
        else { //El punto de inflexion esta a la DERECHA, ya que la funcion decrece
            return resolver(datos, ini, mitad);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num = -1;
    vector<int> datos;
    int aux = -1;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    if (!std::cin)
        return false;

    int sol = resolver(datos, 0, datos.size());

    // escribir sol
    cout << sol << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("34sample.in");
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


















