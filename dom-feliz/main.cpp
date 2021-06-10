//DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
//C37 Y C38


#include <iostream>
#include <iomanip>
#include <fstream>

#include "SetOfInts3.h"



void cuadrados(int n, int &cuadrado) {

	if (n == 0)
		return;

	int dividido = n % 10;
	
	cuadrado = cuadrado + dividido * dividido;

	cuadrados(n / 10, cuadrado);

}


bool esFeliz(int n) {
	bool feliz = (n == 1);
	bool contiene = false;

	int cuadrado = 0;
	SetOfInts3 set;

	cout << n << " ";
	set.add(n);

	while ( !contiene && !feliz ) {
		cuadrado = 0;
		cuadrados(n, cuadrado);
		n = cuadrado;


		cout << cuadrado << " ";

		contiene = set.contains(cuadrado);
		if(!contiene)
		set.add(cuadrado);

		if (cuadrado == 1)
			feliz = true;
		
	} 


	return feliz;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int n = 0;
	cin >> n;

	if (!std::cin)
		return false;
	

	if (esFeliz(n))
		cout << "1"<<endl;
	else 
		cout << "0" << endl;




	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample-C1-2.1.txt");
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
