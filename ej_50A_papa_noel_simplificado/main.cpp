
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

//*******************************
// Explicacion del algoritmo de vuelta atras. 
// Como es la solucion del problema y el arbol de ejecucion
// Coste de la funcion esValida 
//*******************************
struct tDatos {
    int numJuguetes; //Numero de juguetes que se fabrican, dentro de cada juguete hay unidades ilimitadas
    int numNin; //Numero de niños a los que asignar juguetes
};


void escribirSol(vector<int> sol) {
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << ' ';
    }
    cout << endl;
}


bool esValida(vector<int>& sol, int k, int i, tDatos& d, vector<string> juguetes) {
    //Un ninyo no puede tener dos juguetes de un mismo tipo
    if ((k%2) == 1 && juguetes[sol[k - 1]] >= juguetes[sol[k]] ) return false;

    return true;
}
//En cada etapa intentamos repartir todos los juguetes
// Aqui las funciones implementadas por el alumno
int reparte(vector<int>& sol, int k, tDatos& d, vector<string> &juguetes) {
    int numSol = 0;
    for (int i = 0; i < d.numJuguetes; i++) {
        sol[k] = i;
        //Aqui se marcaria
        if (esValida(sol, k, i ,d, juguetes) ) { //Es valida
            if (k == (sol.size() - 1)) { //Es solucion
                numSol++;
                escribirSol(sol);
            }
            else {
                numSol += reparte(sol, k + 1, d, juguetes);
            }
        }
        //Aqui se desmarcaria
    }
    return numSol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos d;

    cin >> d.numJuguetes;
    if (!std::cin)
        return false;
    cin >> d.numNin;

    vector<string> juguetes; //Se caracterizan por su tipo
    juguetes.resize(d.numJuguetes);
    for (int i = 0; i < d.numJuguetes; i++) {
        string aux;
        cin >> aux;
        juguetes[i] = aux;
    }
    
    // LLamar a la funcion de vuelta atras
    vector<int> sol;
    sol.resize(d.numNin * 2); //Cada ninyo tendra dos juguetes
    int k = 0;
    int numSol = 0;
    numSol = reparte(sol, k, d, juguetes);
    //La funcion reparte, escribe os resultados
    if (numSol == 0) {
        cout << "SIN SOLUCION" << endl;
    }
    cout << endl;


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