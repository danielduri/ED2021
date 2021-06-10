// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Queue.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelve(Queue<int> & q, int n){

    std::vector<int> v;

    for (int i = 0; i < n; ++i) {
        int element = q.front();
        q.pop_front();
        v.push_back(element);
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        q.push_back(v[i]);
    }

    std::cout << q << std::endl;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (n==0)
        return false;

    Queue<int> q;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin>>num;
        q.push_back(num);
    }

    resuelve(q, n);

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
