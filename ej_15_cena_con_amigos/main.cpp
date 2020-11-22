// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: E-40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(int &sumaMax, int &diaIni, int &lonMax, vector<int> const& secuencia) {

    int sumRacha = 0;
    int lonRacha = 0;
    for (int i = 0; i < secuencia.size(); i++) { //Bucle que recorre la secuencia de dias
        sumRacha += secuencia[i];
        lonRacha++;
        if (sumRacha > sumaMax) { //Nueva racha maxima
            lonMax = lonRacha;
            sumaMax = sumRacha;
            diaIni = i - lonRacha;
        }
        else if (sumRacha == sumaMax) { //Iguala a la racha anterior
            if (lonRacha < lonMax) { //Nos quedamos con la que tenga menor longitd
                lonMax = lonRacha;
                diaIni = i - lonRacha;
            }
        }
        else {//Se rompe la racha
            sumRacha = 0;
            lonRacha = 0;
        }
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numDias = -1;
    vector<int> secuencia;
    int aux = -1;
    cin >> numDias;
    for (int i = 0; i < numDias; i++) {
        cin >> aux;
        secuencia.push_back(aux);
    }
    if (!std::cin)
        return false;
    int sumaMax = 0; //Suma de la secuencia de dias en la que más hemos engordado
    int diaIni = 0; //Dia que comienza esa secuencia
    int lonMax = 0; //Longitud de la secuencia
    resolver(sumaMax, diaIni, lonMax, secuencia);

    // escribir sol
    cout << sumaMax << " " << diaIni << " " << lonMax << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("15sample.in");
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