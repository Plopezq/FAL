// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using lli = long long int;

//Eliminar digitos pares, dejando solo los impares

// función que resuelve el problema - solucion NO final
lli resolver(lli numero) {
    //Caso base
    if (numero < 10) {
        if (numero %2 == 1) {//Si el numero es impar -> se saca
            return numero;
        } //Si el numero es par -> NO se saca
    }
    //Caso recursivo
    else { //Hacemos la trasnformacion del digito más debil
        if (numero % 2 == 1) { //Si es impar --> se saca
            return resolver(numero/10) * 10 + (numero % 10);
        }
        else { //El numero es par -> NO se saca
            return resolver(numero/10);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli num = -1;
    cin >> num;
    if (!std::cin)
        return false;

    lli sol = resolver(num);

    // escribir sol
    cout << sol << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}