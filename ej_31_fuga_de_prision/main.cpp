// Nombre del alumno: Pablo Lopezp
// Usuario del Juez: E-40

using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
char resolver(vector<char> const& datos, char ini, char fin) {

    if (ini >= fin) return ini; // vector vacio -> CASO BASE
    else {
        if ((ini + 1) == (fin)) {
            return ini; // vector un elemento
        }
        else { // vector 2 o mas elementos
            int mitad = (ini + fin) / 2;
            if ( ((datos[mitad - ini] ) - 'a') < (mitad - 'a') ) { //Busco en la mitad izquierda
                return resolver(datos, ini, mitad);
            }
            else { //Busco en la mitad derecha
                return resolver(datos, mitad, fin);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<char> datos;
    char x1, x2; //Letra del rimer preso y del ultimo
    cin >> x1;
    cin >> x2;
    int z = (x2 - x1) ;

    char aux;
    for (int i = 0; i < z; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    char sol = resolver(datos, x1, x2);
    // escribir sol
    cout << sol << endl;

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