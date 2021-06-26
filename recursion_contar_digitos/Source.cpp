// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//RECURSIVA NO FINAL
int resolver(int numero, int digito) {
    
    if (numero < 10) { //caso base
        if (numero == digito) {
            return 1;
        }
        else {
            return 0;
        }
    }else { //caso recursivo
        if ((numero % 10) == digito) {
            return 1 + resolver(numero / 10, digito);
        }
        else {
            return resolver(numero / 10, digito);
        }
    }
}

//RECURSIVA FINAL
int resolver2(int numero, int digito, int acum) {

    if (numero < 10) { //caso base
        if (numero == digito) {
            return acum + 1;
        }
        else {
            return acum;
        }
    }
    else { //caso recursivo
        if ((numero % 10) == digito) {
            return resolver2(numero / 10, digito, acum + 1);
        }
        else {
            return resolver2(numero / 10, digito, acum);
        }
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    int digito;
    cin >> numero;
    cin >> digito;


    int numVeces1 = resolver(numero, digito);
    int numVeces2 = resolver2(numero, digito, 0);
    // escribir sol
    cout << numVeces1 << " " << numVeces2  << endl;
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