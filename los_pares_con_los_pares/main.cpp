// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;


// función que resuelve el problema
vector<int> resolver(vector<int> & datos) {
    int k = 1;
    int i = 1;
    //Paso previo -> colocar en la posicion 0 el primer par
    int aux = 0;

    if (datos[aux] % 2 == 1) { //Si es impar
        ++aux;
        while (datos[aux] % 2 == 1) {//Busco hasta tener un par
            ++aux;
        }
        swap(datos[0], datos[aux]); 
    }

    while (i < datos.size()) {
        if (datos[k-1]%2 != datos[i]%2) {
            swap(datos[k], datos[i]);
            ++k;
        }
        else {
            ++i;
        }
    }
    datos.resize(k);

    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num = -1;
    vector<int> datos;
    cin >> num;
    if (!std::cin)
        return false;
    int aux = -1;
    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    vector<int> sol = resolver(datos);

    // escribir sol
    if (datos.size()%2  ==  1) {
        for (int i = 0; i < datos.size() - 1; i++) {
            cout << datos[i] << " ";
        }
    }
    else {
        for (int i = 0; i < datos.size() ; i++) {
            cout << datos[i] << " ";
        }
    }
    cout << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("16sample.in");
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