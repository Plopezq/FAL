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

typedef struct {
    bool interesante;
    int acum = 0;
}tSol;
// Aqui la funcion que resuelve el problema
tSol resolver(int numero) {
    
    if (numero < 10) { //Caso base -> numero de 1 digito
        if () {

        }
    }
    else {
        return resolver(numero / 10);
    }




}




// Para lectura de datos y mostrar los resultados
void resuelveCaso() {
    // Lectura de datos
    int numero = -1;
    cin >> numero;
    
    // LLamar a la función que resuelve el problema
    bool sol = resolver(numero);
    
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
