// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/***************COSTE DEL ALGORITMO****************/


// función que resuelve el problema
int resolver(vector<int> const & v1, vector<int> const& v2, int ini, int fin) {
    if (ini + 1 == fin) { //Caso base -> vector de 1 elemento en v2 y 2 elementos en v1
        if (v1[ini] == v2[ini]) { //El que falta es el de la DERECHA de los dos elementos de v1
            return v1[fin];
        }
        else { //El que falta es el de la IZQUIERDA de los dos elementos
            return v1[ini];
        }
    }
    else { //Caso recursivo
        int mitad = (ini + fin) / 2;
        if (v1[mitad] >= v2[mitad]) { // El elemento perdido esta en la derecha
            return resolver(v1, v2, mitad, fin);
        }
        else { //El elemento perdido esta en la izquierda, si es menor o igual
            return resolver(v1, v2, ini, mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v1;
    vector<int> v2;
    int elementos = -1;
    cin >> elementos;
    int aux = -1;
    for (int i = 0; i < elementos; i++) { //Relleno el primer vector
        cin >> aux;
        v1.push_back(aux);
    }
    for (int j = 0; j < elementos - 1; j++) { //Relleno el segundo vector, tiene un elemento menos
        cin >> aux;
        v2.push_back(aux);
    }
    int sol = -1;
    
    if (v1.size() == 1) { //Si el vector 1 tiene longitud 1, esta claro que el segundo tiene longitud 0
        sol = v1[0];
    }else {
        sol = resolver(v1, v2, 0, v2.size()); //Le paso el tamaño de v2
    }
  

    cout << sol << endl;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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

































