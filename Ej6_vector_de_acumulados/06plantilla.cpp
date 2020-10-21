
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
void resolver(std::vector<int> const& a, std::vector<lli>& v, int const f1, int const f2)
{
   // Aqui codigo del estudiante


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
    vector<lli> va;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        // Escribir la respuesta
        resolver(v, va, f1, f2);



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



