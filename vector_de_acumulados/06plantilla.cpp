
// Nombre y apellidos del estudiante
// Usuario del juez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

using lli = long long int;
// Calcula un vector con los valores acumulados
void resolver(std::vector<int>const& v, std::vector<lli> & va){ //Calculo del vector de acumulados
    //Posicion inicial
    long long int aux = 0;
    int pos = 0;
    while (pos < v.size() ){
        aux += v[pos];
        va.push_back(aux);
        pos++;
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;
    // Lee el resto de los datos y calcula el vector de acumulados
    int numAnyos = a2 - a1 + 1;
    vector<int> v; //Vector de los nacimientos ocurridos durante esos anyos
    int i = 0;
    while (i < numAnyos) { //Lectura del vector
        int aux;
        cin >> aux;
        v.push_back(aux);
        i++;
    }
    // Lectura de las preguntas
    int m; std::cin >> m;
    vector<lli> va; //Vector de acumulados (de los nacimientos)
    resolver(v, va); //Calculo el vector de acumulados
    for (int i = 0; i < m; ++i) { //Recorro las preguntas
        int f1, f2;
        std::cin >> f1 >> f2;
        lli resul;
        if (a1 == f1) {
            resul = va[f2 - a1];
        }
        else {
            resul = va[f2 - a1] - va[f1 - a1 - 1];
        }

        cout << resul << endl;
    }
    std::cout << "---\n";

    return true;
}
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    
#ifndef DOMJUDGE
    std::ifstream in("06sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resuelveCaso())
        ;
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



