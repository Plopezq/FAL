// Nombre del estudiante: Pablo López Martín
// Usuario del juez: E-40

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

// Explicación del algoritmo utilizado
    //Tan solo recorro el vector varias veces y utilizo vectores auxiliares para almacenar la informacion importante

// Coste del algoritmo utilizado

// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores){
   // Aqui codigo del estudiante
    vector<int> aux(maximoValores + 1); //Vactor que tiene en cada posicion el numero de veces que se REPITE el valor
    vector<int> solucion; //Vector que devolvemos, con la solcuion. Los valores más repetidos.
    int max = -1;
    for (int i = 0; i < v.size(); i++) { //Bucle que cuenta cuantas veces aparece un determinado valor
        aux[v[i]]++;
    }
    for (int j = 1; j < aux.size();j++) { //Bucle que encuentra el valor MAS REPETIDO de los 12
        if (aux[j] > max) {
            max = aux[j];
        }
    }
    for (int z = aux.size() - 1; z > 0 ; z--) {//Bucle que guarda en el vector solucion, los valores MAS repetidos
        if (aux[z] == max) {
            solucion.push_back(z);
        }
    }
    
    return solucion;
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces
    vector<int> solucion;
    solucion = resolver(v, valorMax);
    //Ordenamos el vector solucion


    // Escribir los valores del vector que ha calculado resolver
    for (int x = 0; x < solucion.size(); ++x) {
        cout << solucion[x] << " ";
    }
    cout << endl;
    return true;
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
