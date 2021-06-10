// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Queue.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void moveNumToFront(Queue<int> & q, int num){
    while (q.front()!=num){
        int element = q.front();
        q.pop_front();
        q.push_back(element);
    }
}

int findMinInQueue(Queue<int> & q, int n){
    int currmin=q.front();
    currmin=q.front();
    for (int i = 0; i < n; ++i) {
        if (q.front()<currmin){
            currmin=q.front();
        }
        int element = q.front();
        q.pop_front();
        q.push_back(element);
    }
    return currmin;
}

void resuelve(Queue<int> & q, int n){

    Queue<int> o;

    for (int i = 0; i < n; ++i) {
        int currmin=findMinInQueue(q, n-i);
        moveNumToFront(q, currmin);
        q.pop_front();
        o.push_back(currmin);
    }

    std::cout << o << std::endl;
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
