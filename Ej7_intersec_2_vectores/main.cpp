// Nombre del alumno: Pablo López Martín
// Usuario del Juez: E40

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void ordena(vector<int>& vector) {
    int n = vector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vector[i] > vector[j]) {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}
// función que resuelve el problema
vector<int> resolver(vector<int> & v1, vector<int> & v2) {
    vector<int> sol;
    //Ordeno lista 1
    ordena(v1);
    //ordeno lista 2
    ordena(v2);
    int pos1 = 0, pos2 = 0;
    while (pos1 < v1.size() && pos2 < v2.size()) {
        // Aqui codigo del alumno
        if (v1[pos1] < v2[pos2]) { //Si no es igual, avanzo en el vector 1
            pos1++;
        }
        else if (v1[pos1] > v2[pos2]) { //Si no es igual, avanzo en el vector 2
+            pos2++;
        }
        else if (v1[pos1] == v2[pos2]) { //En caso de ser iguales, HAY intersección y cojo el valor
            sol.push_back(v1[pos1]);
            pos1++;
            pos2++;
        }
    }


    return sol;
}

// Resuelve un caso dSe prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v1;
    vector<int> v2;
    bool fin = false;

    while (!fin) { //Lectura del vector 1
        int aux;
        cin >> aux;
        if (aux == 0) {
            fin = true;
        }
        else {
            v1.push_back(aux);
        }
    }
    fin = false;
    while (!fin) { //Lectura del vector 2
        int aux;
        cin >> aux;
        if (aux == 0) {
            fin = true;
        }
        else {
            v2.push_back(aux);
        }
    }

    vector<int> sol = resolver(v1, v2);
    // escribir sol
    int contador = 0;
    while (contador < sol.size() ) {
        cout << sol[contador] << " ";
        contador++;
    }
    cout << endl;
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