// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using lli = long long int;

// función recursiva NO final que calcula el numero con los digitos complementarios
lli rec1(lli const numero) { //Done
    //Caso base
    if (numero < 10) {
        return abs(9 - (numero % 10));
    }//Caso recursivo
    else {
        return rec1(numero / 10) * 10 + abs(9 - (numero % 10));
    }
}

//Funcion recursiva NO final que saca el complementario e invierte el numero 
lli rec2(lli const numero, lli const acum) { //Falla con los 0

    //Caso base
    if (numero == 0) {
        return acum;
    }//Caso recursivo
    else {
        return rec2(numero / 10, acum * 10 + abs(9 - (numero % 10)));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli numero = -1;
    cin >> numero;
    lli num1 = rec1(numero);
    lli num2 = rec2(numero, 0);
    // escribir sol
    cout  << num1 << " " << num2  << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}