
//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Pablo Lopez Martin
// Usuario del juez de clase: E-40
//
//***************************************************

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
    vector<int> probPrecipitacion; //La probabilidad de precipitacion
    vector<int> capAbrigos; //Capacidad de cada abrigo de soportar las precipitaciones
};

//*******************************
// Explicacion del algoritmo de vuelta atras. 
// Como es la solucion del problema y el arbol de ejecucion
// Coste de la funcion esValida 
//*******************************

// Aqui las funciones implementadas por el alumno
bool esValida(int i, tDatos& d, int k, vector<int>& sol, vector<int>& marcas) {
    //NO ME PUEDO MOJAR -> El abrigo soporta la cantidad de lluvia que va a caer
    if (d.capAbrigos[i] < d.probPrecipitacion[k]) return false;
    //NO SE PUEDE REPETIR LA MISMA PRENDA 2 DIAS SEGUIDOS
    if (k > 0 && sol[k] == sol[k - 1]) return false;
    //NO SE PUEDE UTILIZAR UN ABRIGO MAS DIAS QUE OTROS
    if (marcas[i] > 2 + (k / 3)) return false;
    return true;
}

int vueltaAtras(tDatos &d, int k, vector<int> &sol, vector<int> &marcas) {
    int numSoluciones = 0;
    for (int i = 0; i < d.capAbrigos.size(); i++) {
        sol[k] = i;
        //MARCAMOS
        marcas[i]++;
        if (esValida(i, d, k, sol, marcas)) { //Si es valida
            if (k == (d.probPrecipitacion.size() - 1)) {//Si es solucion -> la k es igual al numero de dias
                if (sol[0] != sol[k]) { //No usa el mismo abrigo el primer dia y el ultimo
                    ++numSoluciones;
                    //for (int x : sol) std::cout << x << ' '; 
                    //std:: cout << '\n ';
                }
            }
            else {
                numSoluciones += vueltaAtras(d, k + 1, sol, marcas);
            }
        }
        //DESMARCAMOS
        marcas[i]--;
    }
    return numSoluciones;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numDias, numAbrigos;
    std::cin >> numDias; 
    if (numDias == 0) return false;
    std::cin >> numAbrigos;

    tDatos d;

    // leer probabilidad de precipitacion
    d.probPrecipitacion.resize(numDias);
    for (int& i : d.probPrecipitacion) cin >> i;

    // leer caracteristicas de los abrigos
    d.capAbrigos.resize(numAbrigos);
    for (int& i : d.capAbrigos) cin >> i;
    // LLamar a la funcion de vuelta atras
    int k = 0;
    vector<int> sol(numDias); //Combinacion posible
    vector<int> marcas(numAbrigos); //Dias que usamos cada abrigo

    int numCombinaciones = vueltaAtras(d, k, sol, marcas);

    // Escribir resultado
    if (numCombinaciones == 0) std::cout << "Lo puedes comprar\n";
    else std::cout << numCombinaciones << '\n';


    return true;
}
int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {} // Resolvemos
#ifndef DOMJUDGE // para dejar todo como 
    std::cin.rdbuf(cinbuf); 
    system("PAUSE"); 
#endif
    return 0;
}