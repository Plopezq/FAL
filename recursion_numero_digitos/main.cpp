﻿// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using lli = long long int;
//Vale una solucion Final o una NO Final
// función que cuenta el numero de digitos
int resolverRecursiva(lli const num) {
    //Recursion NO FINAL
    //Caso base
    if (num < 10) {//Es el primer digito
        return 1;
    }
    else {//Caso recursivo
        return 1 + resolverRecursiva(num / 10);
    }

}
int resolverRecursiva2(lli const num, int const acumulador) {
    //Recursion FINAL
    //Caso base
    if (num == 0) {//Es el primer digito
        return acumulador;
    }
    else {//Caso recursivo
        return  resolverRecursiva2(num / 10, acumulador + 1);
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli numero = -1;
    cin >> numero;
    if (!std::cin)
        return false;
    int sol, sol2;
    sol = resolverRecursiva(numero); //No final
    sol2 = resolverRecursiva2(numero, 0); //Final
    // escribir sol
     cout << sol2 << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}