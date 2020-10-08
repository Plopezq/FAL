// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> datos, int p) {
    bool sol = false;
    int max1 = datos[0];
    int min2 = datos[p+1];

    int i = 0;
    while (i <= p) {
        if (datos[i] > max1) max1 = datos[i];
        i++;
    }
    int j = p + 1;
    while(j < datos.size()) {
        if (datos[j] <= min2) min2 = datos[j];
        j++;
    }
    if (max1 < min2) sol = true;
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
        //Leo el numero de elementos del vector y la posicion
    int numEle = -1;
    int pos = -1;
    cin >> numEle;
    cin >> pos;

    //Creo el vector, le añado los datos y se lo paso a la funcion resolver
    vector<int> v(numEle);
    for (int& x : v)
    cin >> x;
    if (p )
    bool sol = resolver(v, pos);
    // escribir sol
    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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