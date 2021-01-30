
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
// Explicacion del algoritmo
// Como es la solucion del problema y el arbol de ejecucion
// Coste de la funcion esValida 
//*******************************
struct tDatos {
    int numJuguetes; //Numero de juguetes que se fabrican
    int numNin; //Numero de niños a los que asignar juguetes
    int minSat; //Minima satisfaccion pedida para los niños
    vector<int> unidadesJuguetes; //Unidades de juguetes de cada tipo
    vector<string> tipoJuguetes; //Tipos de juguete
    vector <vector <int > > satis; //Satisfaccion de cada niño con cada juguete
};


void escribirSol(vector<int> sol) {
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << ' ';
    }
    cout << endl;
}


bool esValida(vector<int>& sol, int k, int i, tDatos& d) {
    //Un ninyo no puede tener dos juguetes de un mismo tipo
    if ((k % 2) == 1 && d.tipoJuguetes[sol[k - 1]] >= d.tipoJuguetes[sol[k]]) return false;

    
    return true;
}
//En cada etapa intentamos repartir todos los juguetes
// Aqui las funciones implementadas por el alumno
int reparte(vector<int>& sol, int k, tDatos& d) {
    int numSol = 0;
    for (int i = 0; i < d.numJuguetes; i++) {
        sol[k] = i;
        //Aqui se marcaria
        if (esValida(sol, k, i, d)) { //Es valida
            if (k == (sol.size() - 1)) { //Es solucion
                numSol++;
                escribirSol(sol);
            }
            else {
                numSol += reparte(sol, k + 1, d);
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
    cin >> d.minSat;

    d.unidadesJuguetes.resize(d.numJuguetes);
    for (int i = 0; i < d.numJuguetes; i++) {
        //Leo las unidades de cada juguete
        int aux;
        cin >> aux;
        d.unidadesJuguetes[i] = aux;
    }

    d.tipoJuguetes.resize(d.numJuguetes);
    for (int i = 0; i < d.numJuguetes; i++) {
        string aux;
        cin >> aux;
        d.tipoJuguetes[i] = aux;
    }

    for (int i = 0; i < d.numNin; i++) { //Filas
        vector <int > aux(d.numJuguetes);
        for (int j = 0; j < d.numJuguetes; j++) { //Columnas
            cin >> aux[j];
        }
        d.satis.push_back(aux);
    }

    // LLamar a la funcion de vuelta atras
    vector<int> sol;
    sol.resize(d.numNin * 2); //Cada ninyo tendra dos juguetes
    int k = 0;
    int numSol = 0;
    numSol = reparte(sol, k, d);
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