// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int suma(int n1, int n2) {
    return (n1 + n2) % 10;
}


// recursion NO FINAL
int resolver(int num1, int num2) {

    if (num1 < 10 && num2 < 10) { //caso base 
        return suma(num1, num2);
    }
    else {// caso recursivo
        return resolver(num1 / 10, num2 / 10) * 10 + suma(num1%10, num2%10);
    }

}

//recursion FINAL
int resolver2(int num1, int num2, int acum, int pot) {

    if (num1 < 10 && num2 < 10) { //caso base 
        return suma(num1, num2) * pot + acum;
    }
    else {// caso recursivo
        return resolver2(num1 / 10, num2 / 10,  suma(num1 % 10, num2 % 10) * pot + acum * 10, pot * 10) ;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num1;
    int num2;
    cin >> num1;
    cin >> num2;

    //int sol = resolver2(num1, num2, 0, 1);
    int sol = resolver(num1, num2);
    // escribir sol
    cout << sol << " " << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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