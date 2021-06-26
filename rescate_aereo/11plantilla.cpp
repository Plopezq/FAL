
// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado



// Coste del algoritmo utilizado



// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int & posIni, int& posFin){
    int conSec = 0;  //Contador de la secuencia
    int secMax = 0;
// Codigo del alumno
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > alturaNave) //Continua la racha
        {
            ++conSec;
            if (conSec > secMax)//Mejora la racha anterior, NO iguala, ya que nos quedamos con la que esté más a la izq
            {
                secMax = conSec;
                posIni = i - conSec + 1;
                posFin = i;
            }
            // Si iguala la racha -> no hacemos nada, porque nos quedamos con la anterior
        }
        else { //Fin de la racha actual
            conSec = 0;
        }
    }
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int i, f; //Inicio y final del intervalo
    resolver(v, alturaNave, i, f);
    // Escribir el resultado
    std::cout << i << ' ' << f << "\n";
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
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
