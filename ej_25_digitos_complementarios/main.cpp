// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using lli = long long int;

// función recursiva NO final que calcula el numero con los digitos complementarios
lli rec1(lli numero) {

    //Caso base
    if (numero < 10) {
        return (9 - numero);
    }
    //caso recursivo
    else {
        return rec1(numero / 10) * 10 + (9 - (numero % 10));
    }
}

//Funcion recursiva NO final que invierte el numero que recibe
void rec2(lli numero) {

    //Caso base
    if (numero < 10) {
        cout << numero;
    }
    else { //caso recursivo
        cout << numero % 10;
        rec2(numero / 10);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli numero = -1;
    cin >> numero;
    lli num1 = rec1(numero);
    //lli num2 = rec2(num1);
    // escribir sol
    cout << num1 << " " + rec2(num1) + "" << endl;
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