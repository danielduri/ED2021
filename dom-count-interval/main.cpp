// DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
// C37 y C38


#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeSet.h"

//Coste: lineal en el numero de elementos en el set), puesto que solo recorre el árbol una vez.
//O(n)
/*
 * teorema de la division:
 *
 * a = num llamadas recursivas (caso peor) = 2
 * b = tamaño problema en la llamada = 2 (la mitad)
 * n = el tamaño de los datos (el numero de nodos del arbol, el numero de elementos en el set)
 * k = coste de la parte no recursiva = 0 (constante)
 *
 * como a = 2 > b^k = 2^0 = 1, el coste es
 * n^(log base 2 2) = n^1
 *
 * El coste es lineal en el numero de nodos del arbol
 */

bool resuelveCaso() {
    int numElems, numConsultas;
    std::cin >> numElems >> numConsultas;

    if (! std::cin)
        return false;

    TreeSet<int> set;
    for (int i = 0; i < numElems; ++i) {
        int num;
        std::cin >> num;
        set.insert(num);
    }

    for (int i = 0; i < numConsultas; ++i) {
        int lower, upper;
        std::cin >> lower >> upper;
        std::cout << set.count_interval(lower, upper) << " " << std::endl;
    }

    std::cout << "---" << std::endl;

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