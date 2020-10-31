// Nombre del alumno: Pablo López Martín
// Usuario del Juez: E-40

//Este problema es muy parecido al de las piedras preciosas ------ intervalos de longitud fija
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const& valla, int const intervalo) {
    int p = 0;  //Posicion inicial del intervalo
    int agujeros = 0; //Agujeros del intervalo

    for (int i = 0; i < intervalo; ++i) { //Recorro el primer intervalo 0-3
        if (valla[i] == 0) { //Necesita ser arreglada
            ++agujeros;
        }
    }
    for (int z = intervalo; intervalo < valla.size(); ++z) {
        if (valla[z] == 0) { //Hay un agujero más a la derecha
            p = z - intervalo; //Actualizo el comienzo del intervalo
            ++agujeros;
        } //else -> si no hay agujero, no hacemos nada
        if (valla[z - intervalo] == 1) { //Si hemos perdido 1 agujero
            --agujeros;
        }
    }
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int mv = -1; //Longitud (metros) de la vaya metálica
    int lt = -1; //Longitud (metros) de la tela comprada
    vector<int> valla;
    
    cin >> mv; //Leo metros valla
    if (mv == 0)
        return false;
    cin >> lt; //Leo letros tela comprada
    int aux = -1;
    for (int i = 0; i < mv; i++) { //Lectura vector(valla)
        cin >> aux;
        valla.push_back(aux);
    }

    int sol = resolver(valla, lt);

    // escribir sol
    if (sol == -1) {
        cout << "No hace falta" << endl;
    }
    else {
        cout << sol << endl;
    }

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
