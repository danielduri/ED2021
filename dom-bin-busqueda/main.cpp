// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"
#include "List.h"

bool binarioBusqueda(const Arbin<int>& arbol, int & maxIzq, int & minDer) {
    if(!arbol.esVacio()){
        Arbin<int> hIzq=arbol.hijoIz(), hDer=arbol.hijoDr();

        if(maxIzq>=arbol.raiz()){
            return false;
        }else{
            maxIzq=arbol.raiz();
        }

        if(minDer<=arbol.raiz()){
            return false;
        }else{
            minDer=arbol.raiz();
        }

        return binarioBusqueda(hIzq, maxIzq, minDer) && binarioBusqueda(hIzq, maxIzq, minDer);
    }
    return true;
}

bool binBusqueda(const Arbin<int>& arbol){
    List<int> *inorden;
    inorden = arbol.inorden();
    bool ok= true;
    auto it = inorden->begin();
    int i = 0, size=inorden->size()-1;
    while(ok && i<size){
        if(*it >= *++it){
            ok= false;
        }
        i++;
    }
    return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Arbin<int> arbol;
    arbol = arbol.leerArbol(-1);

    if(binBusqueda(arbol)){
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