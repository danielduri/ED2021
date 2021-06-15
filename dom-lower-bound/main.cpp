// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeSet.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    std::cin >> num;

    if (num==0)
        return false;

    TreeSet<int> set;
    for (int i = 0; i < num; ++i) {
        int n;
        std::cin >> n;
        set.insert(n);
    }

    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        int n;
        std::cin >> n;
        auto ret = set.lower_bound(n);
        if(ret.first){
            std::cout << ret.second << std::endl;
        }else{
            std::cout << "NO HAY" << std::endl;
        }
    }

    std::cout << "---" << std::endl;

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
