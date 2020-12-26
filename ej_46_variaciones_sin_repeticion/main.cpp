// Nombre del alumno: Pablo López Martín
// Usuario del Juez: E-40


using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//Funcion que escribe el vector solucion 
void escribirSol(vector < char> const& sol) {
    for (char c : sol) { //Recorro el vector
        cout << c;
    }
    cout << endl;
}
// función que resuelve el problema
void variaciones(int m, int n, int k, vector<char>& sol, vector<bool>& marcas) {
    for (char i = 'a'; i < 'a' + m; ++i) {
        sol[k] = i;
        if (marcas[i - 'a'] == false) { //Es valida, la letra no esta marcada
            marcas[i - 'a'] = true; //Marcamos
            if (k == (n - 1)) { //Es solucion
                escribirSol(sol);
            }
            else {//Sigue completando la solucion
                variaciones(m, n, k + 1, sol, marcas);
            }
        }
        marcas[i - 'a'] = false; //Desmarcamos
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n; //m elementos tomados de n en n -> En este caso SIN REPETICION
    cin >> m;
    cin >> n;
    if (!std::cin)
        return false;
    vector<char> sol(n); //La solucion tiene longitud n 
    vector<bool> marcas;
    marcas.assign(m, false); //Le doy tamaño y lo pongo a false
    variaciones(m, n, 0, sol, marcas); //La propia funcion de resolver, ya escribe los datos
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