// Nombre del estudiante: Pablo López
// Usuario del juez: 4-40

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este veCtor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y uego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
void particion (std::vector<psi> & v, int &p, int &q) {
    // Aqui codigo del estudiante
    p = 0; //Delimita azul y verde
    q = v.size() - 1; //delimita verde y rojo
    int k = 0;
    while (k <= q) {
        if (v[k].first == 'v') { //Esta bien colocado el verde
            ++k;
        }
        else if(v[k].first == 'a'){ //Esta bien colocado el rojo
            swap(v[p], v[k]);
            ++p;
            ++k;
        }
        else { //en k es rojo
            swap(v[k], v[q]);
            --q;
        }
    }
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    long int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y altura
    for (psi & n : v) {
        std::cin  >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    particion(v, p, q);
    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin()+p);
    std::sort(v.begin()+p, v.begin()+1+q);
    std::sort(v.begin()+1+q, v.end());
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q+1; i < v.size(); ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso()) {} //Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
