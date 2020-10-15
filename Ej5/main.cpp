// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E40

using namespace std;


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



struct tAnyo{
    int inicio = -1;
    int fin = -1;
};

// función que resuelve el problema
vector<int> resolver(vector<int> const &v, tAnyo const &años) {

    return v;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    tAnyo anyos;

    cin >> anyos.inicio;
    cin >> anyos.fin;

    int aux = 1;
    aux+= (anyos.fin - anyos.inicio);

    vector<int> v(aux);

    int i = 0;
    while (i < aux) {
        cin >> v[i];
        i++;
    }

    vector<int> sol = resolver(v, anyos);
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("05sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}