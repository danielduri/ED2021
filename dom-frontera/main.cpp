//Daniel Duran Rivero y Julian Encinas Fuentes
//C37 y C38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Arbin.h"


Arbin<int> * rellena(){
    int elemento;
    std::cin >> elemento;
    if(elemento != -1){
        Arbin<int> * izq = rellena();
        Arbin<int> * der = rellena();
        return(new Arbin<int>(*izq, elemento, *der));
    }else{
        return new Arbin<int>();
    }
}

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

void obtenerFrontera(Arbin<int> * arbol,  list<int> & lista){
    if(!arbol->esVacio()){
        Arbin<int> hIz = arbol->hijoIz();
        Arbin<int> hDer = arbol->hijoDr();

        if (hIz.esVacio() && hDer.esVacio()){
            lista.push_back(arbol->raiz());
        }else if(hIz.esVacio() && !hDer.esVacio()){
            obtenerFrontera(&hDer, lista);
        }else if(!hIz.esVacio() && hDer.esVacio()){
            obtenerFrontera(&hIz, lista);
        }
        else{
            obtenerFrontera(&hIz, lista);
            obtenerFrontera(&hDer, lista);
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    Arbin<int> * arbol = rellena();
    list <int> lista;

    obtenerFrontera(arbol, lista);

    list<int> :: iterator it;
    for (it = lista.begin(); it!=lista.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
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
