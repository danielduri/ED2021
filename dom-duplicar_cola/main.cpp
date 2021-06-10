// Daniel Duran Rivero
// C37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int num;

    std::cin >> num;

    if (! std::cin)
        return false;

    Queue<int> q;

    while (num!=0){
        q.push_back(num);
        std::cin>>num;
    }

    q.duplicate();

    std::cout << q << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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