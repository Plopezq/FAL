// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

// función que resuelve el problema
//RECURSION NO FINAL
int resolver(int numero) {
    if (numero < 10) {//caso base
        return (numero * 10) + numero;
    }
    else {//caso recursivo
        return resolver(numero/10) * 100 + (numero % 10 * 10 + numero % 10)  ;
    }

}
//recursion final
int resolver2(int numero, int acum) {
    if (numero == 0) {//caso base
        return acum;
    }
    else {//caso 
        return resolver2(numero / 10, acum * 100 + (numero % 10 * 10 + numero % 10));
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    int sol1 = resolver(num);
    int sol2 = resolver2(num, 0);
    // escribir sol
    cout << sol1 << " " << sol2 << endl;

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