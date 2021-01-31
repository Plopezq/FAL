
//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Pablo Lopez Martin
// Usuario del juez de clase: E-40
//
//***************************************************

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//*******************************
// Explicacion del algoritmo
// Como es la solucion del problema y el arbol de ejecucion
// Coste de la funcion esValida 
//*******************************
struct tDatos {
    int numObj; //Numero de objetos que se pueden comprar
    int pres; //Presupuesto con el que se cuenta
    vector<pair<int, int>>  costeSuper;
};
struct tSol {
    vector<int> sol;
    int sumaSatis;
};
class comparador {
public:
    bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

//Para escribir la solucion
std::ostream& operator << (std::ostream& salida, std::vector <bool > const& v) {
    for (int i = 0; i < v.size(); ++i)
        if (v[i]) std::cout << i << ' ';
    std::cout << '\n';
    return salida;
}

int inicializarSuperficie(tDatos const& datos, int costeMax) {
    int i = 0; int sumaSuperficie = 0; int sumaCoste = 0;
    while (i < datos.costeSuper.size() && sumaCoste + datos.costeSuper[i].first <= costeMax) {
        sumaSuperficie += datos.costeSuper[i].second;
        sumaCoste += datos.costeSuper[i].first;
        ++i;
    }
    return sumaSuperficie;
}


//En cada etapa intentamos repartir todos los juguetes
// Aqui las funciones implementadas por el alumno
void resolver(tDatos const& datos, int k, std::vector <bool >& sol, int costeAct, 
    int superficieAct, std::vector <bool >& solMejor, int& superficieMejor) {
    // Compra el objeto
    sol[k] = true;
    costeAct += datos.costeSuper[k].first;
    superficieAct += datos.costeSuper[k].second;
    if (costeAct <= datos.pres) { // Si es valida
        if (k == sol.size() - 1) { // Es solucion
            if (superficieAct > superficieMejor) { //Es solucion mejor
                superficieMejor = superficieAct;
                solMejor = sol;
            }
        }
        else {
            resolver(datos, k + 1, sol, costeAct, superficieAct, solMejor, superficieMejor);
        }
     }
    costeAct -= datos.costeSuper[k].first; // Recupera el valor
    superficieAct -= datos.costeSuper[k].second; //Recupera el valor
    // No compra el objeto
    sol[k] = false;
    // Siempre es valido
    if (k = sol.size() - 1) { // Es solucion
        if (superficieAct > superficieMejor) { // Solucion mejor
            superficieMejor = superficieAct;
            superficieMejor = superficieAct;
        }
    }
    else {
        //EN ESTA SOLUCION, NO ESTIMAMOS
        resolver(datos, k + 1, sol, costeAct, superficieAct, solMejor, superficieMejor);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos d;

    cin >> d.numObj;
    if (!std::cin)
        return false;
    cin >> d.pres;
    for (int i = 0; i < d.numObj; i++) {
        int coste, superficie;
        cin >> coste;
        cin >> superficie;
        d.costeSuper.push_back({ coste,superficie });
    }
    //Ordenamos los datos por superficie por unidad de coste
    sort(d.costeSuper.begin(), d.costeSuper.end(), comparador());
    vector<bool> sol(d.numObj);
    int costeAct = 0; int superficieAct = 0;
    int superficieMejor = inicializarSuperficie(d, d.pres);
    std::vector <bool > solMejor;
    resolver(d, 0, sol, costeAct, superficieAct, solMejor, superficieMejor);
    //std:: cout << solMejor; 
    std:: cout << superficieMejor << '\n'; 
    return true;


}
int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso()) {} // Resolvemos
#ifndef DOMJUDGE // para dejar todo como 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}