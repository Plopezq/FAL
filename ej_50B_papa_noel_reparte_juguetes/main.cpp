
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

bool satisface(vector<int> sol, tDatos d) {
    int nyno = 0; //
    for (int z = 0; z < sol.size(); z+=2 ) { //Sumo 2 ya que cada niño tendra 2 juguetes
        int sum = 0;
        sum += d.satis[nyno][sol[z]]; //Sumo la satisfaccion que le produce a ese niño, ese juguete
        sum += d.satis[nyno][sol[z + 1]]; //Sumo la satisfaccion que le produce a ese niño, ese juguete
        if (sum < d.minSat) return false;
        nyno++;
    }
    return true;
}
bool esValida(vector<int>& sol, int k, int i, tDatos& d) {
    //Un ninyo no puede tener dos juguetes de un mismo tipo
    if ((k % 2) == 1 && d.tipoJuguetes[sol[k - 1]] >= d.tipoJuguetes[sol[k]]) return false;
    //Hay unidades de ese juguete
    if (d.unidadesJuguetes[sol[k]] < 0) return false;
    return true;
}
//En cada etapa intentamos repartir todos los juguetes
// Aqui las funciones implementadas por el alumno
int reparte(vector<int>& sol, int k, tDatos& d) {
    int numSol = 0;
    for (int i = 0; i < d.numJuguetes; i++) {
        sol[k] = i;
        //Aqui se marcaria --> restamos las unidades de ese juguete
        --d.unidadesJuguetes[i];
        if (esValida(sol, k, i, d)) { //Es valida
            if (k == (sol.size() - 1)) { //Es solucion
                if (satisface(sol, d)) {
                    numSol++;
                    escribirSol(sol);
                }
            }
            else {
                numSol += reparte(sol, k + 1, d);
            }
        }
        //Aqui se desmarcaria
        ++d.unidadesJuguetes[i];
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
    sol.assign(d.numNin * 2, -1); //Cada ninyo tendra dos juguetes
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