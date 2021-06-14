// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

bool simetrico(const Arbin<char>& hIzq, const Arbin<char>& hDer){
    if(hIzq.esVacio() && hDer.esVacio()) {
        return true;
    }else{
        if(hIzq.numNodos()==hDer.numNodos()){
            if(hIzq.numHojas()==hDer.numHojas()){
                if(hIzq.talla()==hDer.talla()){
                    return (simetrico(hIzq.hijoIz(), hDer.hijoDr())
                        && simetrico(hIzq.hijoDr(), hDer.hijoIz()));
                }
            }
        }
        return false;
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Arbin<char> arbol;
    arbol = arbol.leerArbol('.');

    if(simetrico(arbol.hijoIz(), arbol.hijoDr())){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
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