// Daniel Duran y Julian Encinas
// c37-c38


#include <iostream>
#include <iomanip>
#include <fstream>


#include "Queue.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


//Coste: (caso peor) lineal en n, donde n=numero de elementos de la cola al principio (caso peor)
void resuelveCaso() {
    // leer los datos de la entrada

    Queue <int> q;
    Queue <int> colar;
    int elemento;
    int pringado;
    cin >> elemento;
    while (elemento != -1) {
        q.push_back(elemento);
        cin >> elemento;
    }

    cin >> pringado;
    cin >> elemento;
    while (elemento != -1) {
        colar.push_back(elemento);
        cin >> elemento;
    }

    cout << q << endl;

    if(!colar.empty())
        q.colotas(pringado, colar);


    cout << q << endl;

    // colar.libera();
    // escribir sol


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
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();

    }
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}