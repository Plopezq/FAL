// Nombre del estudiante: Pablo Lopez Martin
// Usuario del juez: E40

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
    // Declaración de variables
    int pos1 = 0, pos2 = 0;
    // Codigo del alumno
        //Recibo 2 vectores ordenados y tengo que devolver 1 vector ordenado
    vector<int> sol;

    while (pos1 < v1.size() && pos2 < v2.size()) {
        // Aqui codigo del alumno
        if (v1[pos1] < v2[pos2]) { 
            sol.push_back(v1[pos1]);
            pos1++;
        }else if(v1[pos1] > v2[pos2] ) {
            sol.push_back(v2[pos2]);
            pos2++;
        }else if (v1[pos1] == v2[pos2] ) { //En caso de ser iguales, cojo del segundo
            sol.push_back(v2[pos2]);
            pos1++;
            pos2++;
        }
    }
    //Para los elementos que queden en alguno de los vectores
    while (pos1 < v1.size()) {
        // Aqui codigo del alumno
        sol.push_back(v1[pos1]);
        pos1++;
        
    }
    while (pos2 < v2.size()) {
        // Aqui codigo del alumno
        sol.push_back(v2[pos2]);
        pos2++;
    }
    return sol;
}


void resuelveCaso() {
    // Lectura de los datos de entrada
    int n1, n2; 
    std::cin >> n1 >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    for (int& i : v1) std::cin >> i;
    for (int & j : v2) std::cin >> j;
    // LLamada a la función que resuelve el problema
    std::vector<int> sol = resolver(v1, v2);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i) 
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

 #ifndef DOMJUDGE
    std::ifstream in("04sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
 #endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
