// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

Arbin<bool> * rellena(){
    char elemento;
    std::cin >> elemento;
    if(elemento=='*'){
        Arbin<bool> * izq = rellena();
        Arbin<bool> * der = rellena();
        return(new Arbin<bool>(*izq, true, *der));
    }else{
        return new Arbin<bool>();
    }
}

void recorre(Arbin<bool> * const & arbol, int & nodos, int & hojas, int & altura){
    if(!(arbol->esVacio())){
        nodos++;
        Arbin<bool> iz = arbol->hijoIz();
        Arbin<bool> dr = arbol->hijoDr();
        if(iz.esVacio() && dr.esVacio()){
            altura++;
            hojas++;
        }
        else if(!(iz.esVacio()) && dr.esVacio()){
            altura++;
            recorre(&iz, nodos, hojas, altura);
        }
        else if(!(dr.esVacio()) && iz.esVacio()){
            altura++;
            recorre(&dr, nodos, hojas, altura);
        }else{
            altura++;
            int tamIzq = 0, tamDer=0;
            recorre(&iz, nodos, hojas, tamIzq);
            recorre(&dr, nodos, hojas, tamDer);
            altura+=max(tamIzq, tamDer);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    Arbin<bool> * arbol = rellena();
    int nodos=0, altura=0, hojas=0;
    recorre(arbol, nodos, hojas, altura);
    //std::cout << arbol->numNodos() << " " << arbol->numHojas() << " " << arbol->talla() << std::endl;
    std::cout << nodos << " " << hojas << " " << altura << std::endl;


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
