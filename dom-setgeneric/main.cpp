#include <iostream>
#include "Set.h"

// Nombre del alumno .....
// Usuario del Juez ......

#include <iomanip>
#include <fstream>
template<typename T>
void contd(Set<T> & set, T centinela){

    int n;
    cin >> n;
    while(set.getSize()<n) {
        T element;
        cin>>element;
        set.add(element);
    }

    T element;
    cin>>element;

    while (element!=centinela){
        if (!set.contains(element) && element > set.getMin()){
            set.removeMin();
            set.add(element);
        }
        cin>>element;
    }

    cout << set << endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    // leer los datos de la entrada

    char tipo;
    cin >> tipo;

    if (! std::cin)
        return false;

    if (tipo=='N'){
        Set<int> set;
        contd(set, -1);
    }else{
        Set<string> set;
        string centinela = "FIN";
        contd(set, centinela);
    }

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