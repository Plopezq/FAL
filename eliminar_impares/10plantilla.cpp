
// Nombre y apellidos del alumno: Pablo López Martín
// Usuario del juez de clase: E-40

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
// La idea de este problema es resolverlo recorriendo una sola vez el vector,
// para ello, utilizaremos un contador (valores buenos) que nos indicará hasta donde son correctos los valores
// Si encontramos un valor incorrecto, tan solo avanzamos en el vector pero NO en el contador


// Coste del algoritmo utilizado



// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver (std::vector<int> & v) {
    // Codigo del alumno
    int valoresBuenos = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) { //Es PAR (es un valor bueno)
            v[valoresBuenos] = v[i];
            ++valoresBuenos;
        }
    }
    v.resize(valoresBuenos);
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
