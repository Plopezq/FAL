// Nombre del alumno: Pablo López Martín    
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/** Explicacion de la solucion:
    Utilizo el algoritmo estudiado de busqueda de segmento maximo, que permite recorrer el vector una unica vez

**/
// función que resuelve el problema
vector<int> resolver(int &numVal, int &secMax, int &numLlan, vector<int> const &datos) {
    vector<int> posLlan; //Vector con el comienzo de cada llano encontrado (mirado desde la derecha)
    int longAct = 1; //Longitud de la racha actual
    secMax = 3; //Longitud de la secuencia maxima encontrada (secuencia mas larga)
    int posSec = 0;
    for (int i = datos.size() - 1; i > 0; i-- ) { //Recorro el vector al reves
        if (datos[i] == datos[i - 1]) {//Continua la racha
            longAct++;
            posSec = i + 1; //Almacenamos el comienzo de la racha, aunque solo lo guardaremos en el vector, si la racha resulta ser buena
            if (longAct > numVal ) { //Nos vale la racha y encima es mayor que numVal, asique de lujo
                numLlan++;
                secMax = longAct;
                //posLlan.push_back(posSec);
            }
            else if (longAct == numVal){ //tenemos una racha de numVal, nos vale
                numLlan++;
                
                77posLlan.push_back(posSec);
            }
        }
        else { //Se rompe la racha
            //Comprobamos si nos es util la racha y la almacenamos
            if (longAct > numVal) posLlan.push_back(posSec);
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
    int numLlan = -1; //Numero de llanos encontrados

    vector<int> sol1 = resolver(numVal, secMax, numLlan, datos);

    // escribir sol


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