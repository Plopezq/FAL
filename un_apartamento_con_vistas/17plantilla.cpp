//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


//*******************************
// Aqui especificación de la función que resuelve el problema. 
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// 
// 
//*******************************



// Aqui la función implementada por el alumno




bool resuelveCaso() {
    int numEdificios; 
    std::cin >> numEdificios;
    if (numEdificios == 0) return false;
    
    // Lectura del resto de los datos
    
    
    
    // LLamada a la funcion que resuelve el problema
    
    
    
    // Escribir el resultado

    
    return true;
}


int main() {
    // Para la entrada por fichero.
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
     #endif
         
    while (resuelveCaso())
        ;
    
    // Para restablecer entrada. 
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
         
    return 0;
}
