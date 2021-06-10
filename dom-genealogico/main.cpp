//DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
//C37 y C38

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

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"


bintree<int> * rellena(){
    int elemento;
    std::cin >> elemento;
    if(elemento != -1){
        bintree<int> * izq = rellena();
        bintree<int> * der = rellena();
        return(new bintree<int>(*izq, elemento, *der));
    }else{
        return new bintree<int>();
    }
}

bool gen(bintree<int> const arbol, int & generaciones) {
    if (!arbol.empty()) {
        int edadpadre = arbol.root();
        bintree<int> mayor = arbol.left();
        bintree<int> menor = arbol.right();

        int gensmayor = generaciones, gensmenor = generaciones;

        if (mayor.empty() && menor.empty()) {
            generaciones++;
            return true;
        }

        if (gen(mayor, gensmayor) && gen(menor, gensmenor)) {
            generaciones = max(gensmayor, gensmenor);
            generaciones++;
            int edadmayor;
            if (!mayor.empty()) {
                edadmayor = mayor.root();
            } else {
                return false;
            }
            if (edadpadre - edadmayor < 18) {
                return false;
            } else {
                if (!menor.empty()) {
                    int edadmenor = menor.root();
                    if (edadmayor - edadmenor < 2) {
                        return false;
                    } else {
                        return true;
                    }
                }else{
                    return true;
                }
            }
        }else{
            return false;
        }
    }else{
        return true;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    bintree<int> * arbol = rellena();
    int generaciones = 0;
    if(gen( * arbol, generaciones)){
        std::cout << "SI " << generaciones << std::endl;
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