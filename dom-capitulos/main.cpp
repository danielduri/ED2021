// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <unordered_set>
#include <queue>
#include <fstream>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int n;
    std::cin >> n;

    std::unordered_set<int> capitulos;
    std::queue<int> ordenEmision;

    int currentMax=0;

    for (int i = 0; i < n; ++i) {
        int cap;
        std::cin>>cap;
        ordenEmision.push(cap);

        if (capitulos.find(cap)!=capitulos.cend()){
            if(ordenEmision.size()>currentMax){
                currentMax=ordenEmision.size()-1;
            }
            while (ordenEmision.front()!=cap){
                capitulos.erase(ordenEmision.front());
                ordenEmision.pop();
            }
            ordenEmision.pop();
        }else{
            capitulos.insert(cap);
        }
        //std::cout << i << ":" << ordenEmision.size() << " ";
    }

    if(ordenEmision.size()>currentMax){
        currentMax=ordenEmision.size();
    }

    std::cout << currentMax << std::endl;

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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}