// Nombre del alumno: Pablo López Martín    
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

/** Explicacion de la solucion:
    Utilizo el algoritmo estudiado de busqueda de segmento maximo, que permite recorrer el vector una unica vez

**/
// función que resuelve el problema
vector<int> resolver(vector<int> const& datos, int const numVal, int& secMax /*variable de salida*/) {
    vector<int> posLlan; //Vector con el comienzo de cada llano encontrado (mirado desde la derecha) -> vector solucion a devolver
    int longAct = 1; //Longitud de la racha actual
    secMax = -1; //Longitud de la secuencia maxima encontrada (secuencia mas larga)
    int posSec = 0;
    secMax = numVal; //Por si no hay ninguno maximo
    int altMax = datos[datos.size() - 1];
    for (int i = datos.size() - 1; i > 0; i--) { //Recorro el vector al reves, desde la derecha
        if (datos[i] == datos[i - 1] && datos[i] >= altMax) {//Continua la racha
            longAct++;
            if (longAct >= numVal) { //Es valida la racha
                if (longAct > numVal) { //La secuencia es maxima
                    secMax = longAct;
                }
                posSec = datos.size() - i ; //Almacenamos el comienzo de la racha que resulta valernos -> mirado por la derecha
                posLlan.push_back(posSec);
            }
        }
        else {//Fin de la racha, hay alguno que nos quita la vista
            longAct = 1;
        }
    }
    return posLlan;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numDatos = -1; //Numero total de datos obtenidos
    int numVal = -1; //Numero de valores iguales iguales que se necesitan para construir
    vector<int> datos;
    int aux = -1;

    cin >> numDatos;
    cin >> numVal;
    for (int z = 0; z < numDatos; z++) {
        cin >> aux;
        datos.push_back(aux);
    }
    if (!std::cin)
        return false;

    int secMax = -1; //Longitus de la secuencia de llanos mas larga
    //Numero de llanos encontrados = sol.size()

    vector<int> sol; //Vector que indica el comienzo de los llanos encontrados
    sol = resolver(datos, numVal, secMax);
    sort(sol.begin(), sol.end(),greater <int >());
    // escribir sol
    if (sol.size() == 0) {
        secMax = 0;
    }
    cout << secMax << " " << sol.size() ;
    for (int z = 0; z < sol.size(); z++) {
        cout << " " << sol[z];
    }
    cout << endl;
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