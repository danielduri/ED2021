// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <set>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int nLineas;
    std::cin >> nLineas;
    if (nLineas==0)
        return false;

    std::map<std::string, std::set<int>> referencias;
    std::cin.ignore();

    for (int i = 0; i < nLineas; i++) {
        std::string palabra;
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        while (iss >> palabra) {
            if(palabra.size()>2){
                for (char & j : palabra) {
                    j = tolower(j);
                }

                referencias[palabra].insert(i+1);

            }
        }
    }

    auto it = referencias.cbegin();
    while (it!=referencias.cend()){
        std::cout << it->first << " ";
        auto itSet = it->second.cbegin();
        while(itSet!=it->second.cend()){
            std::cout << *itSet << " ";
            itSet++;
        }
        std::cout << std::endl;
        it++;
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
