//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Pablo Lopez Martin
// Usuario del juez de clase: E-40
//
//***************************************************

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


//*******************************
// Aqui explicacion del algoritmo y calculo del coste. 
//
//
//
//
//*******************************


// Aqui la funcion que resuelve el problema
bool resolver(int n, int suma, int aux) {
    
    int num = n / 10;
    int dig = n % 10;

    int p = suma - dig; // izquierda
    int q = aux + dig; //derecha

    bool vacio = false, drcha = false, izq = false;
    if (dig != 0) vacio = true;
    if (aux % dig == 0) drcha = true;
    if (p % dig == 0) izq = true;
    if (num == 0)
        return vacio && drcha && izq;
    else
        return vacio && drcha && izq && resolver(num, p, q);

}




// Para lectura de datos y mostrar los resultados
void resuelveCaso() {
    // Lectura de datos
    int numero = -1;
    cin >> numero;
    
    // LLamar a la función que resuelve el problema
    bool sol = resolver(numero, 0, 0);
    
    // Escribir el resultado
    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
}



int main() {
   // Para redireccionar la entrada del juez
#ifndef DOMJUDGE
    std::ifstream in("27sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
 
    int numCasos; std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) 
        resuelveCaso();

   
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
