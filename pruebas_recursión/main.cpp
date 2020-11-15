

using namespace std;
#include <vector>
#include<iostream>


void funcionVector(std::vector<int> const& v, int i, int n) {
	if (i == n - 1) cout << v[i];
	else { 
		funcionVector(v, i + 1, n);
		cout << v[i] << " + "; 
	}
}

void funcionDigitosNumeros(int n) { 
	if (n < 10) {
		cout << n;
	}else {
		funcionDigitosNumeros(n / 10);
		cout << " + " << n % 10;

	} 
}

void main() {
	/* vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	funcionVector(v, 0, v.size());*/

	//funcionDigitosNumeros(123456);




}
