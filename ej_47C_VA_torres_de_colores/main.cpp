// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct datosEntrada {
    int alturaTorre, azules, rojas, verdes;
    std::vector<std::string> colores;
};
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

// Funcion que compruebas las condiciones 
// que se deben cumplir mientras se construye la torre
bool esValida(const int i,const int k, vector<int>& sol, datosEntrada &d, vector<int>& numPiezasColoc) {
    /** i --> el color de la pieza a colocar **/
    /** k -> la posicion en el arbol de soluciones */
    //Comprobamos que nunca se ponen 2 piezas verdes juntas
    if (k > 0 && sol[k] == 2 && sol[k - 1] == 2) return false;
    //Comprobamos que no coloca mas piezas verdes que azules
    if (numPiezasColoc[2] > numPiezasColoc[0]) return false;
    //Comprobamos que tiene disponible piezas
    if ((sol[k] == 0 && numPiezasColoc[0] > d.azules) ||
        (sol[k] == 1 && numPiezasColoc[1] > d.rojas) ||
        (sol[k] == 2 && numPiezasColoc[2] > d.verdes))
        return false;

    return true;
}

// función que resuelve el problema
int permutaciones(datosEntrada &d, int k,  vector<int>& sol, vector<int>& numPiezasColo) {
    int numSol = 0;
    for (int i = 0; i < 3; i++) {
        sol[k] = i;
        ++numPiezasColo[i]; //Incremento las piezas puestas de ese color
        if (esValida(i, k, sol, d, numPiezasColo)) {//Comprobamos las restricciones
            //MARCAMOS
            if (k == (d.alturaTorre - 1)) { //Es solucion, tiene la altura deseada
                //El numero de piezas rojas, debe ser mayor que la suma de las piezas azules y verdes
                if (numPiezasColo[1] > (numPiezasColo[0] + numPiezasColo[2])) {//SI es solucion
                    escribirSol(sol);
                    ++numSol;
                }
            }
            else {
                numSol += permutaciones(d, k + 1, sol, numPiezasColo);
            }
        }
        //DESMARCAMOS
        --numPiezasColo[i];
    }
    return numSol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    datosEntrada d;
    cin >> d.alturaTorre;

    cin >> d.azules; //Piezas de color azul
    cin >> d.rojas; //Piezas de color rojo
    cin >> d.verdes; //Piezas de color verde


    if (d.alturaTorre == 0 && d.azules == 0 && d.rojas == 0 && d.verdes == 0)
        return false;

    //      0 azul, 1 rojo, 2 verde
    vector<int> sol; //vector solucion
    sol.assign(d.alturaTorre, -1);
    vector<int> numPiezasColo; //Vector que nos dice las piezas colocadas de cada color
    numPiezasColo.assign(3, 0);

    if (d.rojas > 0) { //Si tengo piezas de color rojo
        sol[0] = 1; //pongo el rojo en la base
        ++numPiezasColo[1];
    }
    int numSol = 0;
    if (d.alturaTorre > 1) {
        numSol = permutaciones(d, 1, sol, numPiezasColo);
    }
    if(numSol == 0) {
        cout << "SIN SOLUCION" << endl;
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
