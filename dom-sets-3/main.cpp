//DANIEL DURAN RIVERO y JULIAN ENCINAS FUENTES
//C37 Y C38


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SetOfInts3.h"
#include <climits>
#include <vector>

/*
 * getMax() tiene coste constante
 * getMin() tiene coste constante
 * removeMax() tiene coste constante
 * removeMin() tiene coste lineal en k, pues debe eliminar el primer elemento, pero no lo utilizamos
 *
 *
 *
 * La entrada de datos tiene coste lineal en n
 * El algoritmo en el caso peor, que es aquel en el que la entrada esta ordenada de mayor a menor,
 * es de coste O(n*k), ya que la funcion add tiene coste lineal en k.
 */

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int k;
    std::cin >> k;
    // leer los datos de la entrada

    if (k == 0)
        return false;
    else if(k<=100){
        std::vector<int> numeros;
        SetOfInts3 setmenores;

        int nuevo;
        std::cin>>nuevo;

        while (nuevo!=-1){
            numeros.push_back(nuevo);
            std::cin >> nuevo;
        }

        int i=0;

            while (setmenores.getSize()!=k){
                setmenores.add(numeros[i]);
                i++;
            }

            int minactual = setmenores.getMax();
            //Una variable que guarda el maximo del setmenores

            while(i<numeros.size()){
                if (numeros[i]<minactual && !setmenores.contains(numeros[i])){
                    //setgeneral.add(setmenores.getMax());
                    setmenores.removeMax();
                    setmenores.add(numeros[i]);
                    minactual = setmenores.getMax();
                }
                i++;
            }

            std::cout << setmenores << std::endl;
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
