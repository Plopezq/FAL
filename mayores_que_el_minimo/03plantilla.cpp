// Nombre y apellidos del alumno: Pablo Lopez Martín
// Usuario del juez de clase: E40

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

 struct tSol{
    int sum = 0;
    int num = 0;
};
// Explicación del algoritmo utilizado


// Coste del algoritmo utilizado



// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
tSol resolver(vector <int> const& v) {
    // Inicialización de variables
    tSol solucion;
    solucion.num = 1;
    solucion.sum += v[0];
    int valorMin = v[0];
    int numMin = 1;
    // Codigo del alumno
    
    for (int i = 1; i < v.size(); ++i) { //Cambio de i = 1 a i = 0
        // Aqui el código del alumno
        // No deben hacerse más bucles
        if (v[i] < valorMin) {
            valorMin = v[i];
            numMin = 1;
        }else if (v[i]==valorMin) {
            numMin++;
        }
        solucion.num++;
        solucion.sum += v[i];
    }
    solucion.num -= numMin;
    solucion.sum -= (numMin * valorMin);

    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    tSol s = resolver(v);
    // Escribir los resultados
     cout << s.sum << ' ' << s.num << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
 
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
