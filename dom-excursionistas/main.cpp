//DANIEL DURÁN RIVERO y JULIÁN ENCINAS FUENTES
//C37 y C38


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

//Coste: lineal en el numero de nodos del arbol, puesto que solo recorre el árbol una vez.
//O(n)
/*
 * teorema de la division:
 *
 * a = num llamadas recursivas (caso peor) = 2
 * b = tamaño problema en la llamada = 2 (la mitad)
 * n = el tamaño de los datos (el numero de nodos del arbol)
 * k = coste de la parte no recursiva = 0 (constante)
 *
 * como a = 2 > b^k = 2^0 = 1, el coste es
 * n^(log base 2 2) = n^1
 *
 * El coste es constante en el numero de nodos del arbol
 */

void rescate(Arbin<int> const arbin, int & equipos, int & rescatados) {
    if (!arbin.esVacio()){
        int ranterior = rescatados;

        rescate(arbin.hijoIz(), equipos, rescatados);
        int riz=rescatados;

        rescatados=ranterior;

        rescate(arbin.hijoDr(), equipos, rescatados);
        int rder=rescatados;

        rescatados=max(riz, rder);

        if (arbin.raiz()>0){
            if(ranterior == rescatados){
                equipos++;
            }
            rescatados = rescatados+arbin.raiz();
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    Arbin<int> arbol;
    arbol = arbol.leerArbol(-1);

    int equipos=0, rescatados=0;
    rescate(arbol, equipos, rescatados);

    std::cout << equipos << " " << rescatados << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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