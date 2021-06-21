// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using lli = long long int;
struct tSol {
    int num, pot;
};
// función recursiva NO final que calcula el numero con los digitos complementarios
lli rec1NOfin(lli const numero) { //Caso 1 clase
    //Caso base
    if (numero < 10) {
        return abs(9 - (numero % 10));
    }//Caso recursivo
    else { //n >= 10
        return rec1NOfin(numero / 10) * 10 + (9 - numero % 10);
    }
}
lli rec1fin(lli const numero, lli acum, lli pot) { //Caclulamos el numero complementario del dado -- Caso 2 clase
    //Caso base
    if (numero < 10) {
        return (9 - numero % 10) * pot + acum;
    }
    else {//Caso recursivo
        return rec1fin(numero / 10, (9 - numero % 10) * pot + acum, pot * 10);
    }
}

//Funcion recursiva final que saca el complementario e invierte el numero 
lli rec2fin(lli const numero, lli const acum) { //Falla con los 0 -- Caso 3 clase
    //Caso base
    if (numero < 10 ) {
        return acum * 10 + (9 - numero);
    }//Caso recursivo
    else { // n >= 10
        return rec2fin(numero/10, acum * 10 + (9 - numero % 10));
    }
}
tSol rec2NOfin(int const numero) { //Falla con los 0 -- Caso 4 clase

    if (numero < 10) {
        return { 9 - numero, 10 };
    }
    else {
        tSol s = rec2NOfin(numero / 10);
        return{ s.num + (9 - numero % 10) * s.pot, s.pot * 10 };
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    lli numero = -1;
    cin >> numero;
    lli num1 = rec1fin(numero, 0, 1);
    lli num2 = rec2fin(numero, 0);
    // escribir sol
    cout  << num1 << " " << num2 << endl;
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