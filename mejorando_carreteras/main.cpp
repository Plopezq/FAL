// Nombre del alumno: Pablo López Martín
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;


// función que resuelve el problema
int resolver(vector<int> const& vector) {
    //Se busca el tramo que mas accidentes sufre. 
    //Como tenemos el vector odenado, tan solo es buscar el segmento máximo de valores iguales.
    int lonMax = 0;
    int lonAct = 0;
    int posRa = 0; //Ultimo punto donde hubo racha.
    for (int i = 1; i < vector.size(); i++) {
        if (vector[i] == vector[i-1]) {//Continua la racha
            ++lonAct;
            if (lonAct > lonMax) {//Mejora la racha
                lonMax = lonAct;
                posRa = i;
            } //Si iguala la racha, no hacemos nada, ya que nos quedamos con ls de la izq
        }
        else {//Se rompe la racha
            lonAct = 0;
        }
    }
    return (posRa-lonMax);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numAcci;
    cin >> numAcci;
    if (numAcci == -1)
        return false;

    vector<int> accidentes;
    for (int i = 0; i < numAcci; i++) {
        int aux;
        cin >> aux;
        accidentes.push_back(aux);
    }
    sort(accidentes.begin(), accidentes.end());

    int sol = resolver(accidentes);

    //Escribir solucion
    cout << accidentes[sol] << endl;

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
