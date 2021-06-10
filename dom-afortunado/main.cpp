// Daniel Duran Rivero
// C37


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"

int afortunado(Queue<int> & q, int saltos);

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Queue<int> q;
    int n, saltos;
    std::cin >> n >> saltos;
    // leer los datos de la entrada

    if (n==0)
        return false;

    for (int i = 0; i < n; ++i) {
        q.push_back(i+1);
    }

    std::cout << afortunado(q, saltos) << std::endl;

    // escribir sol

    return true;

}

int afortunado(Queue<int> & q, int saltos) {
    int elem;
    while (!(q.empty())){
        //Echamos "saltos" elementos al final de la cola; echando al que, despues de esto, quede en el front.
        //Repetir esto hasta que solo quede un elemento
        for (int i = 0; i < saltos; ++i) {
            elem=q.front();
            q.pop_front();
            q.push_back(elem);
        }
        q.pop_front();
    }
    return elem;
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
