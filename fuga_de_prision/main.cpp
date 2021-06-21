// Nombre del alumno: Pablo Lopezp
// Usuario del Juez: E-40

using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

// función que resuelve el problema
char resolver(vector<char> const& datos, char ini, char fin) {

    //Caso base -> el vector de dos elementos
    if (ini + 1 == fin) { 
        return datos[ini] + 1;
    }
    else { // Funcion recursiva --> vector 2 o mas elemento
        int mitad = (ini + fin) / 2;
        if ( datos[mitad] == char(mitad + datos[0]) ) { //La parte izquierda es Correcta, ya que la mitad esta en su sitio
            return resolver(datos, mitad, fin);
        }
        else {//En la parte izquierda esta el error
            return resolver(datos, ini, mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<char> datos;
    char x1, x2; //Letra del rimer preso y del ultimo
    cin >> x1;
    cin >> x2;
    int z = (x2 - x1) ;

    char aux;
    for (int i = 0; i < z; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    //Comprobamos la precondicion de que ninguno de los extremos es el prisionero fugado
    if (datos[0] != x1) { //Compruebo si el del extremo izquierda es el fugado
        //El fugado es el primero
        cout << x1 << endl;
    }
    else if (datos[datos.size()-1] != x2) { //Compruebo si el del extremo derecha es el fugado
        //El fugado es el ultimo
        cout << x2 << endl;
    }
    else { //Ningun extremo es el fugado
        char sol = resolver(datos, 0, datos.size());
        // escribir sol
        cout << sol << endl;
    }

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