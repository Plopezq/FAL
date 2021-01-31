
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
    vector <vector <int > > satis; //Satisfaccion de cada niño con cada juguete
};
struct tSol {
    vector<int> sol;
    int sumaSatis;
};



//En cada etapa intentamos repartir todos los juguetes
// Aqui las funciones implementadas por el alumno
void reparte(tDatos &datos, int k, tSol &sol, vector<bool> &marcas, int &satisMejor, vector<int> &acum) {
    for (int i = 0; i < datos.numJuguetes; i++) {
        sol.sol[k] = i;
        if (!marcas[i]) { //Es valida -> cuando ese juguete no ha sido usado
            //Actualizo la satisfaccion actual
            sol.sumaSatis += datos.satis[k][i];
            //MARCO
            marcas[i] = true;
            if (k == (sol.sol.size() - 1)) { //Es solucion
                if (sol.sumaSatis > satisMejor) { //Es solucion mejor
                    satisMejor = sol.sumaSatis;
                }
            }
            else { //NO es solucion 
                if (sol.sumaSatis + acum[k+1] > satisMejor) //ESTIMAMOS -> solo seguimos si la solucion va a mejorar, sino no
                    reparte(datos, k + 1, sol, marcas, satisMejor, acum);
            }
            //quito la satisfaccion del jguete anterior
            sol.sumaSatis -= datos.satis[k][i];
            //DESMARCO
            marcas[i] = false;
        }
    }
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
    //Leo el vector de satisfaccion
    for (int i = 0; i < d.numNin; i++) { //Filas
        vector <int > aux(d.numJuguetes);
        for (int j = 0; j < d.numJuguetes; j++) { //Columnas
            cin >> aux[j];
        }
        d.satis.push_back(aux);
    }

    //Calculo el vector de maxima satisfaccion de juguete por ninyo --> para estimar --> para el vector de acumulados
    vector<int> acum(d.numNin);
    for (int j = 0; j < d.numNin; j++) {
        int auxMax = d.satis[j][0];
        for (int z = 0; z < d.numJuguetes; z++) {
            if (d.satis[j][z] > auxMax) auxMax = d.satis[j][z];
        }
        acum[j] = auxMax;
    }

    //Calculo el vector de acumulados de las satisfacciones maximas de los ninyos --> en este caso desde el final al principio
    for (int i = (acum.size() - 1); i > 0 ; i--) {
        acum[i - 1] += acum[i];
    }

    //Inicializo el vector de la solucion mejor y del coste mejor antes de llamar a resolver
    //En este caso no nos piden el vector, asique solo calculo el costeMejor, que sera un coste valido sin mas
    int satisMejor = 0;
    for (int z = 0; z < d.numNin; z++) {
        satisMejor += d.satis[z][z];
    }

    // LLamar a la funcion de vuelta atras
    tSol sol;
    sol.sumaSatis = 0;
    sol.sol.assign(d.numNin, -1); //Cada ninyo tendra un juguete
    vector<bool> marcas; //Para saber si ese juguete ya ha sido asignado o no
    marcas.assign(d.numJuguetes, false);
    int k = 0;
    reparte(d, 0, sol, marcas, satisMejor, acum);

    cout << satisMejor << endl;

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