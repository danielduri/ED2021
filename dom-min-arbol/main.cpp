// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
template <class T>
T min(Arbin<T> arbol){
    if (!arbol.esVacio()){
        Arbin<T> hIzq = arbol.hijoIz(), hDer=arbol.hijoDr();
        T minIzq, minDer;
        if(hIzq.esVacio()){
            minIzq=arbol.raiz();
        }else{
            minIzq=std::min(min(hIzq), arbol.raiz());
        }
        if (hDer.esVacio()){
            minDer=arbol.raiz();
        }else{
            minDer=std::min(min(hDer), arbol.raiz());
        }
        return std::min(minIzq, minDer);
    }
}

bool resuelveCaso() {

    char c;
    std::cin >> c;

    if (! std::cin)
        return false;

    if(c=='N'){
        Arbin<int> arbol;
        arbol = arbol.leerArbol(-1);
        std::cout << min(arbol) << std::endl;
    }else{
        Arbin<string> arbol;
        arbol = arbol.leerArbol("#");
        std::cout << min(arbol) << std::endl;
    }

    // escribir sol


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