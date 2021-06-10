//DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
//C37 Y C38


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SetOfInts3.h"
#include <climits>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int k;
    std::cin >> k;
    // leer los datos de la entrada

    if (k == 0)
        return false;

    SetOfInts3 setmenores;

    for (int i = 0; i < k; ++i) {
        int nuevo;
        cin>>nuevo;
        setmenores.add(nuevo);
    }

    int minactual = setmenores.getMax();
    //Una variable que guarda el maximo del setmenores
    int nuevo;
    cin>>nuevo;

    while (nuevo!=-1){
        if (nuevo<minactual){
            //setgeneral.add(setmenores.getMax());
            setmenores.removeMax();
            setmenores.add(nuevo);
        }
    }

    std::cout << setmenores << std::endl;

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
