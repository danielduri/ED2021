// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

bintree<char> leer(){
    char c;
    std::cin >> c;

    if(c=='.'){
        return bintree<char>();
    }else{
        bintree<char> hIzq=leer();
        bintree<char> hDer=leer();

        return bintree<char>(hIzq, '*', hDer);
    }
}

// altura del árbol
void diametro(const bintree<char>& arbol, int & maximo, int & alt) { // O(n), donde 'n' es el número de nodos en el árbol
    if (arbol.empty()) {
        return;
    } else {
        bintree<char> hIzq=arbol.left(), hDer=arbol.right();
        int altIzq=alt, altDer=alt;
        if(!hIzq.empty()){
            diametro(hIzq, maximo, altIzq);
        }
        if(!hDer.empty()){
            diametro(hDer, maximo, altDer);
        }

        alt=std::max(altIzq, altDer);
        alt++;

        if(altIzq+altDer+1>maximo){
            maximo=altIzq+altDer+1;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> arbol = leer();

    int num=0, alt=0;
    diametro(arbol, num, alt);

    std::cout << num << std::endl;

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