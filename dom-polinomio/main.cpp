// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <fstream>
#include "Polinomio.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int x, y;
    std::cin >> x;

    if (! std::cin)
        return false;

    std::cin >> y;

    Polinomio pol;


    while(x!=0){
        pol.addMonomio(x, y);
        std::cin >> x >> y;
    }

        int num;
        std::cin >> num;
        for (int i = 0; i < num; ++i) {
            int z;
            std::cin >> z;
            std::cout << pol.evaluar(z) << " ";
        }
        std::cout << std::endl;

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