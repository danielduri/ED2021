// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

void aguaslimpias(const Arbin<int>& arbol, int & count, int & caud, bool root){
    if(!arbol.esVacio()){
        if(arbol.hijoDr().esVacio() && arbol.hijoIz().esVacio()){
            caud++;
        }else{
            int caudDr=caud, caudIz=caud;
            aguaslimpias(arbol.hijoIz(), count, caudIz, false);
            aguaslimpias(arbol.hijoDr(), count, caudDr, false);
            caud=caudIz+caudDr-arbol.raiz();
            if (caud<0){
                caud=0;
            }
            if(caud>=3 && !root){
                count++;
            }
        }
    }
}

void aguaslimpias(const Arbin<int>& arbol, int & count, int & caud){
    aguaslimpias(arbol, count, caud, true);
}


void resuelveCaso() {
    Arbin<int> arbol;
    arbol = arbol.leerArbol(-1);
    int count=0, caudal=0;
    aguaslimpias(arbol, count, caudal);

    std::cout << count << std::endl;


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