// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tDatos {
    int num; //numero de funcionarios y de trabajos
    vector<vector<int >> funcTrab; // funcionarios con el tiempo que tardan en hacer cada trabajo
};

struct tSol {
    vector<int> sol; //vector solucion, con tantos elementos como rabajadores haya
    int sumaTiempo;
};

// función que resuelve el problema
void resolver(tDatos& datos, int k, tSol& sol, vector<bool>& marcas, int& tiempoMinimo, vector<int> &acum) {

    for (int i = 0; i < datos.num; i++) {
        sol.sol[k] = i;
        if (!marcas[i]) { //es valido, es decir, ese trabajo no lo esta haciendo otro
            //actualizo el tiempo actual
            sol.sumaTiempo += datos.funcTrab[k][i];
            //marco que ese rabajo ya se esta haciendo
            marcas[i] = true;
            if (k == (sol.sol.size() - 1)) { //si es solucion
                if (sol.sumaTiempo < tiempoMinimo) { //es solucion mejor
                    tiempoMinimo = sol.sumaTiempo;
                }
            }
            else {//no es solucion
                //aqui estimamos
                if (sol.sumaTiempo + acum[k + 1] < tiempoMinimo) //ESTIMAMOS -> solo seguimos si la solucion va a mejorar, sino no
                    //seguimos hasta tener una solucion
                    resolver(datos, k + 1, sol, marcas, tiempoMinimo, acum);
            }
            //ya no se hace ese trabajo
            sol.sumaTiempo -= datos.funcTrab[k][i];
            marcas[i] = false;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;
    int aux;
    cin >> aux;
    datos.num = aux;

    if (aux == 0)
        return false;

    //leemos la matriz

    for (int i = 0; i < datos.num; i++) {
        vector<int> aux2;
        for (int i = 0; i < datos.num; i++) {
            cin >> aux;
            aux2.push_back(aux);
        }
        datos.funcTrab.push_back(aux2);
    }
    //inicializo el struct solucion
    tSol sol;
    sol.sumaTiempo = 0;
    vector<bool> marcas; //Para saber si ese trabajo ya ha sido asignado o no
    marcas.assign(datos.num, false);
    sol.sol.assign(datos.num, 0);


    //Inicializo e tiempo minimo a la diagonal del array, mismamente
    int tiempoMinimo = 0;
    for (int z = 0; z < datos.num; z++) {
        tiempoMinimo += datos.funcTrab[z][z];
    }
    //Calculo el vector de minimo tiempo de trabajo por trabajador --> para estimar --> para el vector de acumulados
    vector<int> acum(datos.num);
    for (int j = 0; j < datos.num; j++) { //Recorro los niños
        int auxMin = datos.funcTrab[j][0];
        for (int z = 0; z < datos.num; z++) { //Recorro los juguetes
            if (datos.funcTrab[j][z] < auxMin) auxMin = datos.funcTrab[j][z];
        }
        acum[j] = auxMin; //Satisfaccion maxima que puede tener un niño
    }
    //Calculo el vector de acumulados del tiempo minimo de los trabajadores --> en este caso desde el final al principio
    for (int i = (acum.size() - 1); i > 0; i--) {
        acum[i - 1] += acum[i];
    }

    resolver(datos, 0, sol, marcas, tiempoMinimo, acum);

    // escribir sol
    cout << tiempoMinimo << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
