
using namespace std;


#include <vector>
#include <iostream>


int main() {

	// Guardan componentes de un MISMO tipo
	vector<int> vect;
	vect = {1, 2, 3};
	vect.push_back(40);


	cout << vect.size() << endl;
	cout << "----------------" << endl;
					//BUCLES EXCLUSIVOS DE VECTORES
	//Recorre desde el principio hasta el final del vector --FORMA ANTICUADA
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it) 
	{
		std::cout << *it << endl;

	}
	cout << "----------------" << endl;
	//Recorre desde el principio hasta el final del vector --FORMA C++11
	for (auto it = vect.begin(); it != vect.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "----------------" << endl;
	//Bucle más comodo
	for (int elemento : vect) {
		cout << elemento << endl;
	}
}