// DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
// C37 y C38

//coste: lineal en el tamaño de la lista: O(n)


#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"


// función que resuelve el problema
void resolver(List<int> & datos) {
    List<int>::Iterator it = datos.begin();
    int anterior = *it;
    while(it!=datos.end()){
        if(*it<anterior){
            it=datos.erase(it);
        }else{
            anterior=*it;
            it++;
        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int num;
    List<int> list;

    std::cin>>num;

    while(num!=-1){
        list.push_back(num);
        std::cin >> num;
    }

    if (!list.empty()){
        resolver(list);
        List<int>::ConstIterator it = list.cbegin();
        int anterior = *it;
        while(it!=list.cend()){
            std::cout<<*it<<" ";
            it++;
        }
    }

    std::cout<<std::endl;

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
