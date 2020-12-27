﻿// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Funcion que compruebas las condiciones 
// que se deben cumplir mientras se construye la torre
bool esValida(const int i,const int k, vector<int>& sol, vector<int>& numPiezasRest, vector<int>& numPiezasColoc) {
    /** i --> el color de la pieza a colocar **/
    /** k -> la posicion en el arbol de rsoluciones */
    //Comprobamos que tiene disponible alguna pieza de ese color
    if ( (numPiezasRest[i] - numPiezasColoc[i]) == 0) return false;
    //Comprobamos que nunca se ponen 2 piezas verdes juntas
    if (k > 0 && sol[k] == 2 && sol[k] == sol[k - 1]) return false;
    //Comprobamos que no coloca mas piezas verdes que azules
    if (numPiezasColoc[2] > numPiezasColoc[0]) return false;

    return true;
}
//Funcion que escribe el vector solucion
void escribirSol(vector<int> const& solucion) {
    for (int z : solucion) {
        if (z == 0) { //AZUL
            cout << "azul ";
        }
        else if (z == 1) { //ROJO
            cout << "rojo ";
        }
        else { //z == 2 --> VERDE
            cout << "verde ";
        }
    }
    cout << endl;
}

// función que resuelve el problema
bool permutaciones(int const altura, int k, vector<int>& sol, vector<int>& numPiezasRest, vector<int>& numPiezasColo) {
    bool posible = false;
    for (int i = 0; i < 3; i++) {
        sol[k] = i;
        if (esValida(i,k, sol, numPiezasRest, numPiezasColo)) {//No tiene dos verdes seguidos
            ++numPiezasColo[i]; //Incremento las piezas puestas de ese color
            if (k == (altura - 1)) { //Es solucion, tiene la altura deseada
                if (numPiezasColo[1] > (numPiezasColo[0] + numPiezasColo[2])) { //El numero de piezas rojas, debe ser mayor que la suma de las piezas azules y verdes
                    escribirSol(sol);
                    posible = true;
                }
                //Volvemos a tener todas las piezas disponibles
                numPiezasColo.assign(3, 0);
            }
            else {
                permutaciones(altura, k + 1, sol, numPiezasRest, numPiezasColo);
            }
        }
    }
    return posible;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int altura = -1;
    cin >> altura;

    vector<int> numPiezasRest(3); //Vector que nos dice las piezas restantes de cada color
    cin >> numPiezasRest[0]; //Piezas de color azul
    cin >> numPiezasRest[1]; //Piezas de color rojo
    cin >> numPiezasRest[2]; //Piezas de color verde


    if (altura == 0 && numPiezasRest[0] == 0 && numPiezasRest[1] == 0 && numPiezasRest[2] == 0)
        return false;

    //      0 azul, 1 rojo, 2 verde
    vector<int> sol(altura); //vector solucion
    vector<int> numPiezasColo; //Vector que nos dice las piezas colocadas de cada color
    numPiezasColo.assign(3, 0);

    bool posible;
    sol[0] = 1; //pongo el rojo en la base, si tengo de color rojo
    if (numPiezasRest[1] > 0) ++numPiezasColo[1];
    if (altura > 1) {
        posible = permutaciones(altura, 1, sol, numPiezasRest, numPiezasColo);
    }
    else {
        escribirSol(sol);
    }
    if (!posible) {
        cout << "SIN SOLUCION";
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
